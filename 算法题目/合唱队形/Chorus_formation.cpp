#include <iostream>
using namespace std;

int n;
int dp[2][101];
int high[101];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>high[i];
    }
    for(int i=1;i<=n;i++){
        dp[0][i]=1;
        dp[1][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(high[i]>high[j])
                dp[0][i] = max(dp[0][i],dp[0][j]+1);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>i;j--){
            if(high[i]>high[j]){
                dp[1][i] = max(dp[1][i],dp[1][j]+1);
            }
        }
    }
    int max_count = 0;
    for(int i=1;i<=n;i++){
        max_count = max(max_count,dp[0][i]+dp[1][i]);
    }
    cout<< (n-max_count+1)<<endl;
    return 0;
}