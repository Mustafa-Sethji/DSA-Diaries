class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;
        int remove=10;
        while(n>=remove){
            n-=remove;
            remove--;
        }
        if(remove%2==0)return false;
        return true;
    }
};