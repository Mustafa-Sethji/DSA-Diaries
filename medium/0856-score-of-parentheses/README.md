# Score of Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a balanced parentheses string `s`, return *the **score** of the string*.

The **score** of a balanced parentheses string is based on the following rule:

- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.

 

**Example 1:**

```
Input: s = "()"
Output: 1

```

**Example 2:**

```
Input: s = "(())"
Output: 2

```

**Example 3:**

```
Input: s = "()()"
Output: 2

```

 

**Constraints:**

- 2 <= s.length <= 50
- s consists of only '(' and ')'.
- s is a balanced parentheses string.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.3 MB (beats 21.13%)  
**Submitted:** 2026-10-05T12:59:12.728Z  

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int x = st.top();
                st.pop();

                int val = (x == 0) ? 1 : 2 * x;
                st.top() += val;
            }
        }

        return st.top();
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/score-of-parentheses/)