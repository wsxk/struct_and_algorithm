class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int i;
        int res = 0;
        sort(nums.begin(),nums.end());
        for(i=0;i<n/2;i++){
            res= max(res,nums[i]+nums[n-i-1]);
        }
        return res;
    }
};