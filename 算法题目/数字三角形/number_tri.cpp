#include <iostream>
#include <string.h>

using namespace std;

#define max_r 1001
int distan[max_r][max_r];
int max_num[max_r][max_r];
int n;

int max_calc(int i,int j){
    if(max_num[i][j]!=-1)
        return max_num[i][j];
    if(i==n){
        max_num[i][j]=distan[i][j];
    }else{
        max_num[i][j]= (max_calc(i+1,j)>max_calc(i+1,j+1)? max_calc(i+1,j):max_calc(i+1,j+1))+distan[i][j];
    }
    return max_num[i][j];
}

int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>(distan[i][j]);
        }
    }
    memset(max_num,-1,sizeof(distan));
    cout<<max_calc(1,1)<<endl;

    return 0;
}