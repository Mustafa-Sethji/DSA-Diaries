# Palindromic Path Queries in a Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an undirected tree with `n` nodes labeled 0 to `n - 1`. This is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates an undirected edge between nodes `ui` and `vi`.

You are also given a string `s` of length `n` consisting of lowercase English letters, where `s[i]` represents the character assigned to node `i`.

You are also given a string array `queries`, where each `queries[i]` is either:

- "update ui c": Change the character at node ui to c. Formally, update s[ui] = c.
- "query ui vi": Determine whether the string formed by the characters on the unique path from ui to vi (inclusive) can be rearranged into a palindrome.

Return a boolean array `answer`, where `answer[j]` is `true` if the `jth` query of type `"query ui vi"​​​​​​​` can be rearranged into a **palindrome**, and `false` otherwise.

 

**Example 1:**

**Input:** n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]

**Output:** [true,false]

**Explanation:**

- "query 0 2": Path 0 → 1 → 2 gives "aac", which can be rearranged to form "aca", a palindrome. Thus, answer[0] = true.
- "update 1 b": Update node 1 to 'b', now s = "abc".
- "query 0 2": Path characters are "abc", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.

Thus, `answer = [true, false]`.

**Example 2:**

**Input:** n = 4, edges = [[0,1],[0,2],[0,3]], s = "abca", queries = ["query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"]

**Output:** [false,false,true]

**Explanation:**

- "query 1 2": Path 1 → 0 → 2 gives "bac", which cannot be rearranged to form a palindrome. Thus, answer[0] = false.
- "update 0 b": Update node 0 to 'b', now s = "bbca".
- "query 2 3": Path 2 → 0 → 3 gives "cba", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.
- "update 3 a": Update node 3 to 'a', s = "bbca".
- "query 1 3": Path 1 → 0 → 3 gives "bba", which can be rearranged to form "bab", a palindrome. Thus, answer[2] = true.

Thus, `answer = [false, false, true]`.

 

**Constraints:**

- 1 <= n == s.length <= 5 * 104
- edges.length == n - 1
- edges[i] = [ui, vi]
- 0 <= ui, vi <= n - 1
- s consists of lowercase English letters.
- The input is generated such that edges represents a valid tree.
- 1 <= queries.length <= 5 * 104​​​​​​​queries[i] = "update ui c" or queries[i] = "query ui vi" 0 <= ui, vi <= n - 1 c is a lowercase English letter.

## Solution

**Language:** C++  
**Runtime:** 359 ms (beats 69.32%)  
**Memory:** 305.7 MB (beats 64.77%)  
**Submitted:** 2026-10-29T06:07:38.125Z  

```cpp

class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy, head, pos;
    vector<int> seg;
    int timer;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            sz[u] += sub;

            if (sub > maxSize) {
                maxSize = sub;
                heavy[u] = v;
            }
        }
        return sz[u];
    }

    void decompose(int u, int h, string& s) {
        head[u] = h;
        pos[u] = timer++;

        update(1, 0, (int)adj.size() - 1,
               pos[u], 1 << (s[u] - 'a'));

        if (heavy[u] != -1)
            decompose(heavy[u], h, s);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;
            decompose(v, v, s);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;
        int ans = 0;

        if (ql <= mid)
            ans ^= query(node * 2, l, mid, ql, qr);

        if (qr > mid)
            ans ^= query(node * 2 + 1, mid + 1, r, ql, qr);

        return ans;
    }

    int pathXor(int u, int v) {
        int ans = 0;
        int n = adj.size();

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            ans ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        ans ^= query(1, 0, n - 1, pos[u], pos[v]);
        return ans;
    }

public:
    vector<bool> palindromePath(
        int n, vector<vector<int>>& edges,
        string s, vector<string>& queries
    ) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        seg.assign(4 * n, 0);
        timer = 0;

        dfs(0, -1);
        decompose(0, 0, s);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;

                update(1, 0, n - 1, pos[u],
                       1 << (c - 'a'));
            } else {
                int v;
                ss >> v;

                int mask = pathXor(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/palindromic-path-queries-in-a-tree/)