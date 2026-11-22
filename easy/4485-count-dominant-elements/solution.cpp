class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int dom=0;
        int n=nums.size();
        if(n==1)return 1;
        for(int i=0;i<nums.size();i++){
            if(i==0 || i==n-1){
                if(i==0 && nums[i]>=nums[i+1])dom++;
                if(i==n-1 && nums[n-1]>=nums[n-2])dom++;
            }
            else if (2*nums[i]>=(nums[i-1]+nums[i+1]))dom++;
        }
        return dom;
    }
};