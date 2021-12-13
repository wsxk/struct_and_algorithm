#include <iostream>
#include <string.h>

using namespace std;
unsigned long long maps[22][22];
int mark[22][22];
int n,m,x,y;

void define_horse(){
    mark[x][y]=1;
    if((x-2)>0&&(y-1)>0)
        mark[x-2][y-1]=1;
    if((x-2)>0&&(y+1)<=m)
        mark[x-2][y+1]=1;
    if((x-1)>0&&(y-2)>0)
        mark[x-1][y-2]=1;
    if((x-1)>0&&(y+2)<=m)
        mark[x-1][y+2]=1;
    if((x+1)<=n&&(y-2)>0)
        mark[x+1][y-2]=1;
    if((x+1)<=n&&(y+2)<=m)
        mark[x+1][y+2]=1;
    if((x+2)<=n&&(y-1)>0)
        mark[x+2][y-1]=1;
    if((x+2)<=n&&(y+1)<=m)
        mark[x+2][y+1]=1;
    mark[x][y]=1;
}
int main(){
    memset(maps,0,sizeof(maps));
    memset(mark,0,sizeof(mark));
    cin>>n>>m>>x>>y;
    n++;
    m++;
    x++;
    y++;
    define_horse();
    maps[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!mark[i][j]){
                maps[i][j]=maps[i-1][j]+maps[i][j-1];
            }
        }
    }
    cout<<maps[n][m]<<endl;
}