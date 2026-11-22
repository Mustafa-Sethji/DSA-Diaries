class Solution {
public:
    long long minCost(vector<int>& nums) {

        int n=nums.size();
        long long cost=LLONG_MAX;
        int i=0;
        while(i<n){
            int k=i+1;

            while(k<n && nums[k]==nums[i])k++;

            int curr_size=k-i;
            if(curr_size==n)return 0;

            if(!((i==0 || i==n-1) && curr_size==1)){
                cost=min(cost,1LL*nums[i]*(n-curr_size));
            }
            i=k;
        }
        return cost;
    }
};