#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct ball{
    double x,y,z;
}balls[1001];

int T,n,h,r;
int visted[1001]={0};
int mark;

int cmp(ball &a,ball &b){
    return a.z<b.z;
}

int check(ball &a,ball &b){
    double x_2 = (b.x-a.x)*(b.x-a.x);
    double y_2 = (b.y-a.y)*(b.y-a.y);
    double z_2 = (b.z-a.z)*(b.z-a.z);
    if(sqrt(x_2+y_2+z_2)<=2*r){
        return 1;
    }
    return 0;
}
void dfs(int i){
    if(balls[i].z+r>=h){
        mark=1;
        return;
    }
    if(mark==1){
        return;
    }
    visted[i]=1;
    for(int j=1;j<=n;j++){
        if(!visted[j]&&check(balls[i],balls[j])){
            dfs(j);
        }
    }
}

int main(){
    cin>>T;

    while(T--){
        cin>>n>>h>>r;
        for(int i=1;i<=n;i++){
            cin>>balls[i].x>>balls[i].y>>balls[i].z;
        }
        memset(visted,0,sizeof(visted));
        //memset(balls,0,sizeof(balls));
        mark = 0;
        sort(balls+1,balls+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(balls[i].z>r){
                break;
            }else{
                dfs(i);
            }
            if(mark){
                break;
            }
        }
        if(mark){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}