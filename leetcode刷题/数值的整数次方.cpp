class Solution {
public:
    double myPow(double x, int n) {
        double sum = 1;
        long long a =n;
        if(n<0){
            x = 1/x;
            a = -a;
        }
        while(a){
            if(a&1)
                sum *= x;
            x *= x;
            a = a>>1;
        }
        return sum;
    }
};