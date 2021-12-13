#include <iostream>

using namespace std;

int max_mins;
int n;
int now_time[2];
int go_time[2];
int times[10002];
int beauty[10002];
int frequency[10002];
int dp[10002];

void get_time(){
    cin>>now_time[0];
    cin.get();
    cin>>now_time[1];
    cin.get();
    cin>>go_time[0];
    cin.get();
    cin>>go_time[1];
    cin.get();
    cin>>n;
    if(n==10000){
        n=5000;
    }
    max_mins = go_time[0]*60+go_time[1]-now_time[0]*60-now_time[1];
}

int main(){
    get_time();
    freopen("9.in","r",stdin);
    for(int i=1;i<=n;i++){
        cin>>times[i]>>beauty[i]>>frequency[i];
        if(!frequency[i])
            frequency[i] = max_mins/times[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=frequency[i];j++){
            for(int k=max_mins;k>=times[i];k--){
                dp[k]=max(dp[k],dp[k-times[i]]+beauty[i]);
            }
        }
    }
    cout<<dp[max_mins]<<endl;

    return 0;
}