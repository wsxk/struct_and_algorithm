#include <stdio.h>

int n;
unsigned long long years_num[60]={0};

int main(){
    years_num[1]=1;
    years_num[2]=2;
    years_num[3]=3;
    years_num[4]=4;
    for(int i=5;i<55;i++){
        years_num[i]=years_num[i-1]+years_num[i-3];
    }
    scanf("%d",&n);
    while (n!=0)
    {
		printf("%d\n",years_num[n]);
      	scanf("%d",&n);
    }
    return 0;
}
/*
#include <iostream>

using namespace std;
int n;
unsigned long long years_num[60]={0};

unsigned long long calc(int num){
    if(years_num[num]){
        return years_num[num];
    }else{
        years_num[num] = calc(num-1)+calc(num-3);
    }
    return years_num[num];
}
int main(){
    years_num[1]=1;
    years_num[2]=2;
    years_num[3]=3;
    years_num[4]=4;
    for(int i=5;i<55;i++){
        years_num[i]=years_num[i-1]+years_num[i-3];
    }
    cin>>n;
    while (n!=0)
    {
        //calc(n);
        cout<<years_num[n]<<endl;
        cin>>n;
    }
    return 0;
}*/