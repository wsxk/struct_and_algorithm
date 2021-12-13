#include <iostream>
#include <cstring>
using namespace std;

int n;
int store_num[4003]={0};
int pre_sum[4003]={0};//i-j堆的总大小
unsigned long long dp[4003][4003]={0};

/*
unsigned long long sum(int i,int j){
    unsigned long long test=0;
    for(int a=i;a<=j;a++){
        test+=store_num[a];
    }
    return test;
}*/

int main(){
    freopen("2.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>store_num[i];
        store_num[i+n]=store_num[i];
        //dp[i][i]=store_num[i];
    }

    for(int i=1;i<=2*n;i++){
        pre_sum[i]=pre_sum[i-1]+store_num[i];
    }

    for(int i=n;i>=1;i--){
        for(int j=i+1;j<i+n;j++){
            dp[i][j]=max(dp[i+1][j],dp[i][j-1])+pre_sum[j]-pre_sum[i-1];
        }
    }



    /*
    for(int i=2;i<=n;i++){
        for(int j=1;j<2*n-i;j++){
            for(int k=j;k<i+j-1;k++){
                dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][k]+dp[k+1][j+i-1]);
            }
            dp[j][j+i-1] += pre_sum[j+i-1]-pre_sum[j-1];
        }
    }*/
    unsigned long long max_num=0;
    for(int i=1;i<=n;i++){
        max_num=max(max_num,dp[i][i+n-1]);
    }
    cout<<max_num<<endl;
    return 0;
}