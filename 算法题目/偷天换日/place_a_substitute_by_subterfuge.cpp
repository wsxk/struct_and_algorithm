#include <iostream>

using namespace std;

int n;
int dp[10010][10010];
int value[2001];
int cost_time[2001];

void read_arg(int k){
    int t,x;
    cin>>t>>x;
    t = t<<1;//go and back
    if(x){  //have draws
        for(int i=1;i<=x;i++){
            cin>>value[i]>>cost_time[i];
        }
        for(int i=1;i<=x;i++){
            for(int j=n;j>=t+cost_time[i];j--){
                dp[k][j]= max(dp[k][j],dp[k][j-cost_time[i]]+value[i]);
            }
        }
    }else{
        read_arg(k<<1);
        read_arg(k<<1|1);
        for(int i=n;i>=t;i--){
            for(int j=0;j<=i-t;j++){
                dp[k][i] = max(dp[k][i],dp[k<<1][j]+dp[k<<1|1][i-j-t]);
            }
        }
    }
}
int main(){
    cin>>n;
    n--; //leave at x-1
    
    read_arg(1);
    cout<<dp[1][n];
    
    return 0;
}