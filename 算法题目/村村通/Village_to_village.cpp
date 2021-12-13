#include <iostream>
#include <cstring>
using namespace std;

int n;int m;
int father[1001];

int find(int n){
    if(father[n]==n)
        return n;
    return find(father[n]);
}

int main(){
    cin>>n>>m;
    while(n||m){
        for(int i=1;i<=n;i++){
            father[i]=i;
        }
        for(int i=1;i<=m;i++){
            int x;int y;
            int fx;int fy;
            cin>>x>>y;
            fx=find(x);fy=find(y);
            father[fx]=fy;
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(father[i]==i){
                count++;
            }
        }
        cout<<count-1<<endl;
        cin>>n>>m;
    }
    return 0;
}