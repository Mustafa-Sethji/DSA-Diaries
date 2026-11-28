class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int close=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int current=abs(target-sum);
                if(close>current){
                    close=current;
                    ans=sum;
                }
                if(sum<target)j++;
                else k--;
            }
        } 
        return ans;
    }
};