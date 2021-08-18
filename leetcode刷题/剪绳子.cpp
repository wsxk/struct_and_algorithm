class Solution {
public:
    int cuttingRope(int n) {
        long long max_product = 0;
        for(int m=2;m<=n;m++){
            int len = n/m;
            int k = n%m;
            long long val = (long long)pow(len+1,k)*(long long)pow(len,m-k);
            if(val > max_product)
                max_product = val;
        }
        return max_product;
    }
};