class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> mark(n,0);
        function<bool(int)> is_safe = [&](int x){
            if(mark[x]>0){
                return mark[x]==2;
            }
            mark[x] = 1;
            for(int y : graph[x]){
                if(!is_safe(y)){
                    return false;
                }
            }
            mark[x] = 2;
            return true;
        };
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(is_safe(i))
                ans.push_back(i);
        }
        return ans;
    }

};