#include <iostream>
#include <cstring>
using namespace std;
#define max_n 1002

int mapp[max_n][max_n];
int dp1[max_n][max_n],dp2[max_n][max_n],dp3[max_n][max_n],dp4[max_n][max_n];
int n,m;

int main(){
    int i,j;
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    memset(dp3,0,sizeof(dp3));
    memset(dp4,0,sizeof(dp4));
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            scanf("%d",&mapp[i][j]);
    }
    // 1 1 
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+mapp[i][j];
        }
    }
    // n 1
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            dp2[i][j] = max(dp2[i][j-1],dp2[i+1][j])+mapp[i][j];
        }
    }
    // 1 m
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp3[i][j] = max(dp3[i][j+1],dp3[i-1][j]) +mapp[i][j];
        }
    }
    // n m
    for(i=n;i>=1;i--){
        for(j=m;j>=1;j--){
            dp4[i][j] = max(dp4[i][j+1],dp4[i+1][j])+mapp[i][j];
        }
    }
    int max_calories = -1;
    for(i=2;i<n;i++){
        for(j=2;j<m;j++){
            max_calories = max(max_calories,dp1[i-1][j] + dp4[i+1][j] + dp2[i][j-1] + dp3[i][j+1]);
            max_calories = max(max_calories,dp1[i][j-1] + dp4[i][j+1] + dp2[i+1][j] + dp3[i-1][j]);
        }
    }
    printf("%d\n",max_calories);
    return 0;
}