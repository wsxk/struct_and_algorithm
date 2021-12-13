#include <iostream>
#define max_num 20
using namespace std;
unsigned long long count_num[max_num+1];
unsigned long long combination_num[max_num+1][max_num+1];

void init(){
    for(int i=0;i<=max_num;i++){
        combination_num[i][0]=1;
    }
    combination_num[1][1]=1;
    for(int i=2;i<=max_num;i++){
        for(int j=1;j<=i;j++){
            combination_num[i][j]=combination_num[i-1][j]+combination_num[i-1][j-1];
        }
    }
    count_num[0]=2;
    count_num[1]=2;
    count_num[2]=2;
    count_num[3]=4;
    count_num[4]=10;
    for(int i=5;i<=max_num;i++){
        unsigned long long tmp=0;
        for(int j=0;j<=i;j++){
            tmp += combination_num[i-1][j]*(count_num[j]/2)*(count_num[i-j-1]/2);
        }
        count_num[i]=tmp;
    }
}

int main(){
    int n;
    int num,people;

    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&num,&people);
        printf("%d ",num);
        if(people==1)
            printf("1\n");
        else
            printf("%llu\n",count_num[people]);
    }
    return 0;
}