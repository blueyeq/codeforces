#include<cstdio>

const int maxn=300+10;
char st[maxn][maxn];
int n,m,p;

int main()
{
        scanf("%d%d%d",&n,&m,&p);
        for (int i=1;i<=n;i++) scanf("%s",st[i]+1);
        for (int k=1;k<=n;k++)
        {

                for (int i=1+k;i+k<=n;i++)
                for (int j=1+k;j+k<=m;j++)
                if (st[i][j]=='*'
                    && st[i-k][j]=='*' && st[i+k][j]=='*'
                    &&st[i][j-k]=='*' && st[i][j+k]=='*')
                   {
                        p--;
                        if (!p)
                        {
                                printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i,j,i-k,j,i+k,j,i,j-k,i,j+k);
                                return 0;
                        }
                   }
        }
        printf("-1\n");
}
