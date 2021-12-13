//#include <iostream>
//using namespace std;
#include <stdio.h>
int main(){
    //freopen("9.in","r",stdin);
    //freopen("9.out","w",stdout);
    unsigned long long plane[10001];
    int c;
    int n;
    plane[1]=2;
    plane[2]=7;
    for(int i=3;i<=10000;i++){
        plane[i]=plane[i-1]+4*(i-1)+1;
    }
    scanf("%d",&c);
    //cin>>c;
    for(int i=0;i<c;i++){
        //cin>>n;
        scanf("%d",&n);
        printf("%llu\n",plane[n]);
        //cout<<plane[n]<<endl;
    }
    return 0;
}