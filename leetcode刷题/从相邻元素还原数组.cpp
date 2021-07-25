class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto &pairs:adjacentPairs){
            mp[pairs[0]].push_back(pairs[1]);
            mp[pairs[1]].push_back(pairs[0]);
        }
        int n = adjacentPairs.size()+1;
        vector<int> ret(n);
        for(auto &[index,value]:mp){
            if(value.size()==1){
                ret[0]=index;
                break;
            }
        }
        ret[1]=mp[ret[0]][0];
        for(int i=2;i<n;i++){
            ret[i]= (ret[i-2]==mp[ret[i-1]][0])? mp[ret[i-1]][1]:mp[ret[i-1]][0];
        }
        return ret;
    }
};