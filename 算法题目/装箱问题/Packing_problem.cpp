#include <iostream>

using namespace std;

int n;
int V;
int value[31];
int dp[20001];

int main(){
    cin>>V;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=V;j>=value[i];j--){
            dp[j] = max(dp[j],dp[j-value[i]]+value[i]);
        }
    }
    cout<<V-dp[V]<<endl;
    return 0;
}