# Reverse Substrings Between Each Pair of Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should **not** contain any brackets.

 

**Example 1:**

```
Input: s = "(abcd)"
Output: "dcba"

```

**Example 2:**

```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

```

**Example 3:**

```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

```

 

**Constraints:**

- 1 <= s.length <= 2000
- s only contains lower case English characters and parentheses.
- It is guaranteed that all parentheses are balanced.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.5 MB (beats 91.95%)  
**Submitted:** 2026-09-27T08:34:20.191Z  

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                int j = st.top();
                st.pop();

                reverse(s.begin() + j + 1, s.begin() + i);
            }
        }

        string ans;

        for (char c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)