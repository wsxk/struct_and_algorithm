#include <iostream>

using namespace std;

int n,m;
int weight[26];
int importance[26];
int dp[30001];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>weight[i]>>importance[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=weight[i];j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+importance[i]*weight[i]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}