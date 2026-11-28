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