class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0,max_ans = nums[0];
        for(auto &x:nums){
            pre = max(pre+x,x);
            max_ans = max(max_ans,pre);
        }
        return max_ans;
    }
};