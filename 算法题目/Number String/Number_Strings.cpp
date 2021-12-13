#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=1010;
const int MOD=1000000007;
char str[MAXN];
int dp[MAXN][MAXN];
int main()
{
    while(scanf("%s",&str)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int n=strlen(str)+1;
        dp[1][1]=1;
        for(int i=2;i<=n;i++)
        {
            char ch=str[n-i];
            if(ch=='?')
            {
                for(int j=1;j<=i-1;j++)
                {
                    dp[i][1]+=dp[i-1][j];
                    dp[i][1]%=MOD;
                }
                for(int j=2;j<=i;j++)
                {
                    dp[i][j]=dp[i][j-1];
                    dp[i][j]%=MOD;
                }

            }
            else if(ch=='I')
            {
                dp[i][i]=0;
                for(int j=i-1;j>=1;j--)
                {
                    dp[i][j]=dp[i][j+1]+dp[i-1][j];
                    dp[i][j]%=MOD;
                }

            }
            else if(ch=='D')
            {
                dp[i][1]=0;
                for(int j=2;j<=i;j++)
                {
                     dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                     dp[i][j]%=MOD;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=dp[n][i];
            ans%=MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}