class Solution {
public:
    int maxDepth(string s) {
        int lvl=0,maxi=0;
        for(char ch : s){
            if(ch=='(') maxi=max(++lvl,maxi);
            else if(ch==')') lvl--;
        }
        return maxi;
    }
};