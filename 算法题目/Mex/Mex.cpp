#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#define ll long long
//#define maxn 4001000
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//#define rep(i,a,b) for(int i=a;i<=b;i++)
//const ll P=1e9+7;
using namespace std;
//map<int,int> p;
int n,a[201000],pre[201000],s[201000];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
    	if(n==0) break;
    	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    	memset(pre,0,sizeof(pre));
    	memset(s,0,sizeof(s));
    	ll ans=0,add=0;
		for(int i=1;i<=n;i++,ans+=add)
		if(a[i]<=n)
		{
			int temp=pre[a[i]];
			pre[a[i]]=i;
			for(int j=a[i];j<=n;j++)
			{
				s[j]=j==0?pre[j]:min(s[j-1],pre[j]);
				if(s[j]>temp) add+=s[j]-temp;
				else break;
			}
		}
		printf("%lld\n",ans); 
	}
}