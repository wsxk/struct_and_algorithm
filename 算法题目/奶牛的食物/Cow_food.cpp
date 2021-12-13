#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int state[13];
int possible[400];
int possible_count = 0;
long long dp[13][400],ans[13];

int main(){
    cin>>m>>n;

    int tmp;
    //状态压缩
    memset(state,0,sizeof(state));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp;
            state[i]= (state[i]<<1)+tmp;
        }
    }

    //找到没有相邻合法空地的状况
    for(int i=0;i<=(1<<n);i++){
        if((i&(i<<1))==0){
            possible[++possible_count]=i;
        }
    }
    //看第一行所有可能的情况
    for(int j=1;j<=possible_count;j++){
        if((possible[j]|state[1])==state[1]){
            dp[1][j]=1,ans[1]++;
        }
    }

    //后面的状态都和前一行的状态有关
    for(int i=2;i<=m;i++){
        for(int j=1;j<=possible_count;j++){
            if((possible[j]|state[i])==state[i]){
                for(int k=1;k<=possible_count;k++){
                    if(((possible[k]|state[i-1])==state[i-1])&&((possible[j]&possible[k])==0)){
                        dp[i][j] = (dp[i][j]+ dp[i-1][k]) % 100000000;
                        ans[i] = (ans[i]+dp[i-1][k])%100000000;
                    }
                }
            }
        }
    }
    cout<<ans[m]<<endl;
    return 0;
}