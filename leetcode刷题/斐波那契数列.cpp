class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        long long N_1 = 1;
        long long N_2 = 0;
        long long  N ;
        for(int i=2;i<=n;i++){
            N = (N_1+N_2)%1000000007;
            N_2 = N_1;
            N_1 = N;
        }
        return N;
    }
};