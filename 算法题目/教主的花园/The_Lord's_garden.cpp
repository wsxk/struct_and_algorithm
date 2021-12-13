#include <iostream>
#include <string.h>
using namespace std;
#define inf 0x3f3f3f3f;
long long dp[100001][5];
int ten[100001],twenty[100001],thirty[100001];
int n;
long long max_value=0;
long long the_max(long long a,long long b){
    return a>b? a:b;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ten[i]>>twenty[i]>>thirty[i];
    }
    memset(dp,0,sizeof(dp));
    dp[1][1] = ten[1]; dp[1][2]=-inf;dp[1][3]=-inf;dp[1][4]=-inf;
    for(int i=2;i<=n;i++){
        dp[i][1] = max(dp[i-1][2],dp[i-1][4])+ten[i];
        dp[i][2] = dp[i-1][1]+twenty[i];
        dp[i][3] = dp[i-1][4] + twenty[i];
        dp[i][4] = max(dp[i-1][1],dp[i-1][3])+thirty[i];
    }
    max_value = max(dp[n][2],dp[n][4]);

    dp[1][1] = -inf; dp[1][2]=twenty[1];dp[1][3]=-inf;dp[1][4]=-inf;
    for(int i=2;i<=n;i++){
        dp[i][1] = max(dp[i-1][2],dp[i-1][4])+ten[i];
        dp[i][2] = dp[i-1][1]+twenty[i];
        dp[i][3] = dp[i-1][4] + twenty[i];
        dp[i][4] = max(dp[i-1][1],dp[i-1][3])+thirty[i];
    }
    max_value = max(dp[n][1],max_value);

    dp[1][1] = -inf; dp[1][2]=-inf;dp[1][3]=twenty[1];dp[1][4]=-inf;
    for(int i=2;i<=n;i++){
        dp[i][1] = max(dp[i-1][2],dp[i-1][4])+ten[i];
        dp[i][2] = dp[i-1][1]+twenty[i];
        dp[i][3] = dp[i-1][4] + twenty[i];
        dp[i][4] = max(dp[i-1][1],dp[i-1][3])+thirty[i];
    }
    max_value = max(max_value,dp[n][4]);

    dp[1][1] =-inf; dp[1][2]=-inf;dp[1][3]=-inf;dp[1][4]=thirty[1];
    for(int i=2;i<=n;i++){
        dp[i][1] = max(dp[i-1][2],dp[i-1][4])+ten[i];
        dp[i][2] = dp[i-1][1]+twenty[i];
        dp[i][3] = dp[i-1][4] + twenty[i];
        dp[i][4] = max(dp[i-1][1],dp[i-1][3])+thirty[i];
    }
    max_value = max(max_value,max(dp[n][1],dp[n][3]));

    cout<<max_value<<endl;
    return 0;
}