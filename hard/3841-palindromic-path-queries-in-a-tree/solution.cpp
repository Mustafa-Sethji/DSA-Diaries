
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
