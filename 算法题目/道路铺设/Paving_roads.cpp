#include <iostream>

using namespace std;

int n;
int depth[100001];
int total=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>depth[i];
    }

    depth[0]=0;
    for(int i=1;i<=n;i++){
        if(depth[i]>depth[i-1]){
            total += depth[i]-depth[i-1];
        }
    }
    cout<<total<<endl;
    return 0;
}