#include <iostream>

using namespace std;

int n,m,p;
int joint_search_set[5001];

int find_std(int n){
    if(joint_search_set[n]!=n){
        find_std(joint_search_set[n]);
    }else
        return n;
}

int main(){
    int x,y;

    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        joint_search_set[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        joint_search_set[find_std(x)]=find_std(y);
    }
    for(int i=1;i<=p;i++){
        cin>>x>>y;
        if(find_std(x)==find_std(y))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}