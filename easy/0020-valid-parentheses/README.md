# Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

 

**Example 1:**

**Input:** s = "()"

**Output:** true

**Example 2:**

**Input:** s = "()[]{}"

**Output:** true

**Example 3:**

**Input:** s = "(]"

**Output:** false

**Example 4:**

**Input:** s = "([])"

**Output:** true

**Example 5:**

**Input:** s = "([)]"

**Output:** false

 

**Constraints:**

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10 MB (beats 6.20%)  
**Submitted:** 2026-10-01T07:40:36.437Z  

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch:s){
            if(ch=='(' || ch=='[' || ch=='{')st.push(ch);
            else {
                if(ch==')' && (st.empty() || st.top()!='(')) return false;         
                else if(ch==']' && (st.empty() || st.top()!='[')) return false;
                else if(ch=='}' && (st.empty() || st.top()!='{')) return false;
                st.pop();
            }
        }    
        if(st.empty()) return true;
        return false;            
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)