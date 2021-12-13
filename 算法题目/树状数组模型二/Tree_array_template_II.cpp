#include <iostream>
using namespace std;

int n, m;
int a[500005] = {0}, c[500005]; //对应原数组和树状数组
int lowbit(int x)
{
    return x & (-x);
}
void updata(int i, int k)
{ //在i位置加上k
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}
int getsum(int i)
{ //求D[1 - i]的和，即A[i]值
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    cin >> n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        updata(i, a[i] - a[i - 1]); //输入初值的时候，也相当于更新了值
    }
    while(m--){
        int x,y,z,k;
        cin>>x;
        if(x==1){
            cin>>y>>z>>k;
            updata(y,k);
            updata(z+1,-k);
        }else{
            cin>>y;
            cout<<getsum(y)<<endl;
        }
    }

    return 0;
}