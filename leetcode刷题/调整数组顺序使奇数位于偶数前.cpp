class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()==0)
            return nums;
        int left =0;
        int right = nums.size()-1;
        int n = nums.size()-1;
        while(left<right){
            while(left<n&&nums[left]%2)
                left++;
            while(right>=0&&!(nums[right]%2))
                right--;
            if(left<n&&right>=0&&left<right){
                int tmp = nums[left];
                nums[left]=nums[right];
                nums[right]=tmp;
            }
        }
        return nums;
    }
};