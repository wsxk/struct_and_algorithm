#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int N;
double Q;
int int_Q;
int fare[32];
int fare_num;
int dp[3000100];

int main(){
    int m,a,b,c,total,flag;
    char type;
    double value;
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    while(cin>>Q>>N&&N){
        fare_num=0;
        int_Q = Q*100;
        for(int i=0;i<N;i++){
            flag = 1;a=0;b=0;c=0;
            cin>>m;
            while(m--)
            {
                cin>>type;
                cin.get();
                cin>>value;
                //cout<<value<<" "<<(int)(value*100)<<endl;
                cin.get();
                if(type=='A'){
                    a += (value*100+0.5);
                }else if(type=='B'){
                    b += (value*100+0.5);
                }else if(type=='C'){
                    c += (value*100+0.5);
                }else{
                    flag=0;
                }
            }
            total = a+b+c;
            if(total<=100000&&a<=60000&&b<=60000&&c<=60000&&flag){
                fare[fare_num++]=total;
            }
        }
        memset(dp,0,sizeof(dp));
        /*
        for(int k=0;k<fare_num;k++)
        {
            for(int z = int_Q;z >= fare[k];z-=1)
                dp[z] = max(dp[z],dp[z - fare[k]] + fare[k]);
        }*/
        int situations = 1<<fare_num;
        int max_num;
        int tmp = 0;
        for(int k=0;k<situations;k++){
            tmp = 0;
            for(int z=0;z<fare_num;z++){
                tmp += ((k>>z)&1)*fare[z];
            }
            if(tmp<=int_Q)
                max_num = max(tmp,max_num);
        }
        printf("%.2f\n",max_num/100.0);
    }

    return 0;
}