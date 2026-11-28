class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int j=n-1,i=0;
        int ans=INT_MIN;
        while(i<j){
            int mini=min(height[i],height[j]);
            int area=mini*(j-i);
            ans=max(area,ans);
            if(height[i]<height[j])i++;
            else if(height[i]>height[j])j--;
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};