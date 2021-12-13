#include <iostream>
#include<algorithm>
using namespace std;

int m,n,count1,flag,min_time;
struct Edge{
    int x,y,t;
}edge[100001];
int f[1001]={0};

int cmp(Edge &a,Edge &b){
    return a.t<b.t;
}

int find_std(int n){
    if(f[n]==n)
        return n;
    return find_std(f[n]);
}

int main(){
    //freopen("1.in","r",stdin);
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].t;
    }
    sort(edge+1,edge+m+1,cmp);

    for(int i=1;i<=n;i++){
        f[i]=i;
    }

    count1=0;
    flag = 0;
    min_time=0;
    for(int i=1;i<=m;i++){
        int tmp1 = find_std(edge[i].x);
        int tmp2 = find_std(edge[i].y);
        if(tmp1!=tmp2){
            f[tmp1]=tmp2;
            count1++;
            if(edge[i].t>min_time){
                min_time=edge[i].t;
            }
        }
        if(count1==(n-1)){
            flag=1;
            break;
        }
    }

    if(!flag){
        cout<<"-1"<<endl;
    }else{
        cout<<min_time<<endl;
    }
    return 0;    
}