class Solution {
public:
    vector<int>precompute;
    vector<vector<int>>dp;
    int min_price;
    int n;
    int solve(int i,vector<vector<int>>& item,int budget){
        if(budget==0)return 0;
        if(i==n)return budget/min_price;

        if(dp[i][budget]!=-1)return dp[i][budget];

        int price=item[i][1];
        int buy=0;

        if(price<=budget){
            buy=1+precompute[i]+solve(i+1,item,budget-price);
        }

        int skip=solve(i+1,item,budget);

        return dp[i][budget]=max(buy,skip);

    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        precompute.assign(n,0);
        min_price=INT_MAX;
        
        for(int i=0;i<n;i++){
            min_price = min(min_price, items[i][1]);
            int fac_i=items[i][0];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int fac_j=items[j][0];
                if(fac_j%fac_i==0)precompute[i]++;
            }
        }

        dp.assign(n+1,vector<int>(budget+1,-1));

        return solve(0,items,budget);

    }
};