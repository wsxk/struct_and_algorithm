class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int before = nums[0];
        for(int i=1;i<n;i++){
            if(before == nums[i])
                return before;
            before = nums[i];
        }
        return before;
    }
};