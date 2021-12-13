#include <cstdio>
#include <iostream>
using namespace std;
int sum[30001],fat[30001],toh[30001],t,ans;
int find(int x)
{
	if(fat[x]==x)
		return x;
	int t1=fat[x],t2=find(fat[x]);
	fat[x]=t2;
	toh[x]+=toh[t1];
	return t2;
}
void unionn(int r1,int r2)
{
	int f1=find(r1),f2=find(r2);
	fat[f2]=f1;
	toh[f2]=sum[f1];
	sum[f1]+=sum[f2];
	sum[f2]=0;
}
int abs(int op)
{
	return op<0?-op:op;
}
int main()
{
	char ds;
	int u,v;
	for(int i=1;i<=30000;i++)
	{
		fat[i]=i;
		sum[i]=1;
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>ds;scanf("%d %d",&u,&v);
		if(ds=='M')
		{
			unionn(v,u);
		}
		else
		{
			if(find(u)!=find(v))
				printf("-1\n");
			else
				printf("%d\n",abs(toh[u]-toh[v])-1);
		}
	}
}