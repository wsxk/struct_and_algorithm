class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;               
        int right = nums.size()-1; 
        int mid;
        int border_r;   //右边界
        int border_l;   //左边界
        //先查找右边界的位置
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]<=target){      //如果中间值小于或者等于target，说明target的右边界位于中间值的右侧，所以移动数组的左界限
                left = mid+1;
            }else{
                right =mid-1;           //中间值如果大于target，说明target的右边界位于中间值的左侧，所以移动数组的右界限。
            }
        }
        border_r = left;

        //查找左边界的位置
        left = 0;
        right = nums.size()-1;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]<target){//如果中间值小于target，说明target的左边界位于中间值的右侧，所以移动数组的左界限
                left = mid+1;
            }else{
                right = mid-1;//中间值如果大于或等于target，说明target的左边界位于中间值的左侧，所以移动数组的右界限。
            }
        }
        border_l = right;

        return (border_r-border_l-1);  
    }
};