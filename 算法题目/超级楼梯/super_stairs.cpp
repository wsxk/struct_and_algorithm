#include <iostream>
using namespace std;
int main(){
    int n;
    unsigned long long method[50];
    int M;

    method[1]=0;
    method[2]=1;
    method[3]=2;
    for(int i=4;i<=40;i++)
        method[i] = method[i-1]+method[i-2];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>M;
        cout<<method[M]<<endl;
    }
    return 0;
}