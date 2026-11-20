class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i,int inc,vector<int>&nums){
        if(i>=n)return 0;
        if(dp[i][inc]!=-1)return dp[i][inc];

        int len=1;
        int currval=nums[i]+inc;
        int j=find_method(currval+1,nums,i+1);

        if(j!=-1)
            len=max(len,1+solve(j,0,nums));
        
        j=find_method(currval,nums,i+1);

        if(j!=-1)
            len=max(len,1+solve(j,1,nums));
        
        return dp[i][inc]=len;
    }

    int find_method(int x,vector<int>&nums,int start){
        int j=lower_bound(nums.begin()+start,nums.end(),x)-begin(nums);
        if(j<n && nums[j]==x)return j;
        return -1;
        
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        n=nums.size();
        int result=1;
        dp.assign(n,vector<int>(2,-1));

        for(int i=0;i<n;i++){
            result=max(result,max(solve(i,0,nums),solve(i,1,nums)));
        }
        
        return result;
    }
};