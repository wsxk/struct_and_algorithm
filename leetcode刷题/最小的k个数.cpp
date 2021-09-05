class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size()==0||k==0)
            return {};
        sort(arr.begin(),arr.end());
        vector<int> ret;
        for(int i=0;i<k;i++){
            ret.push_back(arr[i]);
        }
        return ret;
    }
};