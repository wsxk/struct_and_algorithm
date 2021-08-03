class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        vector<int> nums_copy(nums);
        sort(nums_copy.begin(),nums_copy.end());
        int left = 0;
        while(nums_copy[left]==nums[left]){
            left++;
        }
        int right = nums.size()-1;
        while(nums[right]==nums_copy[right]){
            right--;
        }

        return right-left+1;
    }
};