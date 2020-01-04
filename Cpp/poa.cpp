#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=60;
const double eps=1e-6;
const double INF=2000000000.0;
 
int n;
double d[maxn][maxn];
struct node
{
    double x,y;
}a[maxn];
 
double area(node a,node b,node c)
{
    return fabs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))/2.0;
}
 
int judge(int i,int j,int k)
{
    double s=area(a[i],a[j],a[k]);
    for(int x=0;x<n;x++)
    {
        if(x==i||x==j||x==k)
            continue;
        double sum=area(a[i], a[j], a[x]) + area(a[i], a[k], a[x]) + area(a[k], a[j], a[x]);
        if(fabs(sum-s)<eps)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].x>>a[i].y;
        for(int i=1;i<=n-1;i++)
            d[i][i+1]=-10;
        for(int len=2;len<=n-1;len++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+len;
                if(j>n) break;
                d[i][j]=INF;
                for(int k=i+1;k<j;k++)
                {
                    if(!judge(i,k,j)) continue;
                    if(j==i+2)
                        d[i][j]=area(a[i],a[k],a[j]);
                    else
                    {
                        double s=area(a[i],a[k],a[j]);
                        d[i][j]=min(d[i][j],max(max(d[i][k],d[k][j]),s));
                    }
                }
            }
        }
        printf("%.1f\n",d[1][n]);
    }
    return 0;
}

