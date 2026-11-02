class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int opr=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2==1){
            n/=2;
            for(int i=0;i<nums.size();i++){
                opr+=abs(nums[n]-nums[i]);
            }
        }
        else{
            n/=2;
            for(int i=0;i<nums.size();i++){
                opr+=abs(nums[n]-nums[i]);
            }
            n-=1;
            int opr1=0;
            for(int i=0;i<nums.size();i++){
                opr1+=abs(nums[n]-nums[i]);
            }
            opr=min(opr1,opr);
        }
        return opr;
    }
};