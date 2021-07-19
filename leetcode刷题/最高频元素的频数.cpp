class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());  //先排序（从小到大）
        int n = nums.size();            //数组大小
        long long total = 0;
        int l=0,r=1;
        int res = 1;
        for(r=1;r<n;r++){               //右边界从1开始遍历，直到最大
            total += (long long)(r-l)*(nums[r]-nums[r-1]);      //增加一个滑块的大小与k进行比较
            while(total>k){
                total -= nums[r]-nums[l++];//如果大于k，说明已经不能再往前覆盖，需要减少面积
            }
            res = max(res,r-l+1);//取一个最大值的频数
        }
        return res;
    }
};