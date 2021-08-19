class Solution {
public:
    int cuttingRope(int n) {
        if(n==2||n==3)
            return n-1;
        long ret = 1;
        int count = n/3;
        int mul = 1;
        int remain = n%3;
        if(remain == 1){
            count -= 1;
            mul = 4;
        }else if(remain==2){
            mul = 2;
        }
        while(count>0){
            ret *= 3;
            ret = ret %1000000007;
            count--;
        }
        return ret*mul %1000000007;
    }
};