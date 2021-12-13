#include <iostream>

using namespace std;

int m,n;
int weight[1001]; //max weight 1000
int value[1001];    // max value 1000
int dp[1001];
int belong[201][201];//每个分组的所属id，找weight和value用的
int calc[201];//每个分组的数量
int max_belongs=0;

int main(){
    cin>>m>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>weight[i]>>value[i]>>x;
        max_belongs = max(x,max_belongs);
        calc[x]++;
        belong[x][calc[x]]=i;
    }

    for(int i=1;i<=max_belongs;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=calc[i];k++){
                if(j>=weight[belong[i][k]]){
                    dp[j] = max(dp[j],dp[j-weight[belong[i][k]]]+value[belong[i][k]]);
                }
            }
        }
    }
    /*
    for(int i=1;i<=max_belongs;i++){
        for(int k=1;k<=calc[i];k++){
            for(int j=m;j>=weight[belong[i][k]];j--){
                dp[j] = max(dp[j],dp[j-weight[belong[i][k]]]+value[belong[i][k]]);
            }
        }
    }*/ 
    cout<<dp[m]<<endl;
    return 0;
}