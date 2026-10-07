# Remove Invalid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *a list of **unique strings** that are valid with the minimum number of removals*. You may return the answer in **any order**.

 

**Example 1:**

```
Input: s = "()())()"
Output: ["(())()","()()()"]

```

**Example 2:**

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

```

**Example 3:**

```
Input: s = ")("
Output: [""]

```

 

**Constraints:**

- 1 <= s.length <= 25
- s consists of lowercase English letters and parentheses '(' and ')'.
- There will be at most 20 parentheses in s.

## Solution

**Language:** C++  
**Runtime:** 60 ms (beats 50.83%)  
**Memory:** 20.1 MB (beats 41.53%)  
**Submitted:** 2026-10-07T05:36:56.640Z  

```cpp
class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            }
            else if (c == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string curr = q.front();
                q.pop();

                // If valid, this is minimum removal level
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // Don't generate next level once valid strings are found
                if (found)
                    continue;

                // Remove one parenthesis
                for (int i = 0; i < curr.size(); i++) {

                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) +
                                  curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // We found all valid strings with minimum removals
            if (found)
                break;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/remove-invalid-parentheses/)