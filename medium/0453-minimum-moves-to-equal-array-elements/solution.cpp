class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int opr=0;
        for(int i=0;i<nums.size();i++){
            if(mini!=nums[i])opr+=nums[i]-mini;
        }
        return opr;
    }
};