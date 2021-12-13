#include <iostream>

using namespace std;
int N;
unsigned long long num[5001];
unsigned long long dp[5001][2];

int main(){
    //freopen("1.in","r",stdin);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        dp[i][0]=1;
        dp[i][1]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(num[i]<num[j]){
                int tmp1=dp[i][0];
                int tmp2=dp[j][0]+1;
                if(tmp1==tmp2){
                    dp[i][1]+= dp[j][1];
                }if(tmp1<tmp2){
                    dp[i][0]=tmp2;
                    dp[i][1]=dp[j][1];
                }
            }
        }
    }
    unsigned long long tmp=0;
    unsigned long long count1=0;
    for(int i=1;i<=N;i++){
        if(dp[i][0]>tmp){
            tmp=dp[i][0];
            count1=dp[i][1];
        }else if(dp[i][0]==tmp){
            count1+=dp[i][1];
        }
    }
    cout<<tmp<<' '<<count1<<endl;
    return 0;
}