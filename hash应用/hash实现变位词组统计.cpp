class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;//无序容器
        for(string &str: strs){     //遍历strs
            string key = str;       
            sort(key.begin(),key.end());//排序key的内容
            mp[key].emplace_back(str);//压栈
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin();it!=mp.end();++it){
            ans.emplace_back(it->second); //mp是hash无序容器，it>second得到其值
        }
        return ans;
    }
    
};