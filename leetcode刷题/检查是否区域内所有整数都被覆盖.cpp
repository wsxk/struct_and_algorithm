class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(),ranges.end());
        for(auto &range:ranges){
            if(range[0]<=left&&range[1]>=left)
                left = range[1]+1;
        }
        return left>right;
    }
};