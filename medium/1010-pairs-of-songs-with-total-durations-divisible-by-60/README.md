# Pairs of Songs With Total Durations Divisible by 60

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a list of songs where the `ith` song has a duration of `time[i]` seconds.

Return *the number of pairs of songs for which their total duration in seconds is divisible by* `60`. Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

 

Original
C++
**Example 1:**

```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

```

**Example 2:**

```
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.

```

 

**Constraints:**

- 1 <= time.length <= 6 * 104
- 1 <= time[i] <= 500

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 23.11%)  
**Memory:** 32.1 MB (beats 14.39%)  
**Submitted:** 2026-11-28T12:50:38.532Z  

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;

        int n=time.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            int rem = time[i] % 60;
            int complement = (60 - rem) % 60;

            if(mp.find(complement) != mp.end()) {
                cnt += mp[complement];
            }
            mp[rem]++;
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)