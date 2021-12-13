#include <iostream>

using namespace std;

int n,W;
int value[10001];
int weight[10001];
int dp[40001];
int calc=1;

int main(){
    int x,value_tmp,weight_tmp,num;
    //freopen("9.in","r",stdin);
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&value_tmp,&weight_tmp,&num);
        for(int j=1;j<=num;j<<=1){
            value[calc]=value_tmp*j;
            weight[calc]=weight_tmp*j;
            calc++;
            num -=j;
        }
        if(num){
            value[calc]=value_tmp*num;
            weight[calc]=weight_tmp*num;
            calc++;
        }
    }
    for(int i=1;i<calc;i++){
        for(int j=W;j>=weight[i];j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[W]<<endl;
    return 0;
}