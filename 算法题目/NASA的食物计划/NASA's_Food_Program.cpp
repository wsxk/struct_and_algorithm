#include <iostream>

using namespace std;

int quality,volume;
int N;
int each_quality[51];
int each_volume[51];
int each_calarie[51];
int dp[401][401];

int main(){
    cin>>volume>>quality;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>each_volume[i]>>each_quality[i]>>each_calarie[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=quality;j>=each_quality[i];j--){
            for(int k=volume;k>=each_volume[i];k--){
                dp[j][k] = max(dp[j][k],dp[j-each_quality[i]][k-each_volume[i]]+each_calarie[i]);
            }
        }
    }
    cout<<dp[quality][volume]<<endl;
    return 0;
}
