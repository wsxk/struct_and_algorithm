#include <iostream>
using namespace std;

int n,m;
int a[500005],c[500005]; //对应原数组和树状数组

int lowbit(int x){
    return x&(-x);
}

void updata(int i,int k){    //在i位置加上k
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i){        //求A[1 - i]的和
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        updata(i,a[i]);
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            updata(y,z);
        }else{
            if(y>=z)
                cout<<getsum(y)-getsum(z-1)<<endl;
            else
                cout<<getsum(z)-getsum(y-1)<<endl;
        }
    }
    return 0;
}