class Solution {
public:
    int numWays(int n) {
        if(n==0||n==1)
            return 1;
        if(n==2)
            return 2;
        int n1 = 1,n2=2;
        for(int i=3;i<=n;i++){
            long long n3 = (n1+n2)%1000000007;
            n1 = n2;
            n2 = n3;
        }
        return n2;
    }
};