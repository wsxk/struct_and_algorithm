#include <iostream>

using namespace std;

int main(){
    //freopen("1.txt","w",stdout);
    int n,a,b;
    unsigned long long dist[50];
    dist[0]=0;
    dist[1]=1;
    dist[2]=2;
    for(int i=3;i<50;i++)
        dist[i]=dist[i-1]+dist[i-2];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        printf("%llu\n",dist[b-a]);
    }
    return 0;
}