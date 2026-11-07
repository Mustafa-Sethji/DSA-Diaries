
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,int x, vector<int>& queries) {
        for(int i=0;i<logs.size();i++){
            int temp=logs[i][0];
            logs[i][0]=logs[i][1];
            logs[i][1]=temp;
        }
        sort(logs.begin(),logs.end());
        for(int i=0;i<logs.size();i++){
            int temp=logs[i][0];
            logs[i][0]=logs[i][1];
            logs[i][1]=temp;
        }
        vector<pair<int,int>>timeIndex(queries.size());

        for(int i=0;i<queries.size();i++) timeIndex[i]={queries[i],i};
        
        sort(timeIndex.begin(),timeIndex.end());
        vector<int>ans(queries.size());

        int i=0,j=0;
        unordered_map<int,int>mp;
        for( auto it:timeIndex){
            int start=it.first-x;
            int end=it.first;
            while(j<logs.size() && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<logs.size() && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0)mp.erase(logs[i][0]);
                i++;
            }
            ans[it.second]=n-mp.size();
        }
        return ans;

    }
};
