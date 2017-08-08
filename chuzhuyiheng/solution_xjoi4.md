[比赛链接](http://www.hzxjhs.com:83/contest/775)

# 比赛中解决的问题
## A
### Problem description
>给出n,m,求把nm个糖分成最少的k份使可以分为n份m个和m份n个

### Data Limit：n,m<= 1e4  Time Limit: 1s

### Solution
>设n<=m则先取n个n,然后就变成了(m-n,n)的子问题,为了防tle,可以把-改为/.

### Code
```cpp
#include<cstdio>
long long n,m,i,j,t,ans=0;
long long a[10000000],top=0;
int main()
{
    scanf("%lld%lld%lld",&n,&m,&t);
    if (n>m)
    {
        i=n;n=m;m=i;
    }
    if(t==0)
    {
        while (m%n)
        {
            ans+=(m/n)*n;
            m-=(m/n)*n;
            if (n>m)
            {
                i=n;n=m;m=i;
            }
        }
        ans+=m;
        printf("%lld",ans);return 0;
    }
    while (m%n)
    {
        ans+=n;
         
        for (i=1;i<=n;i++)
        {
            top++;a[top]=n;
        }
        m-=n;
        if (n>m)
        {
            i=n;n=m;m=i;
        }
    }
    ans+=m;
    printf("%lld\n",ans);
    for (i=1;i<=(m);i++)
        {
            top++;a[top]=n;
        }
    for (i=1;i<=top;i++)printf("%lld ",a[i]);
    return 0;
```
*****

# 赛后补题


## B
### Problem description
>给出一张图,求1到n的对k取模的最短路.

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
> 详见http://www.hzxjhs.com:83/contest/775/problem/2/solution

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define pr(x,y) make_pair(x,y)
const int N=50010,M=N<<1;
int n,m,qn,x,y,z,s,t,k,fr[N],f[N][2],tot,fi[N],ne[M],a[M],c[M],d[N];
inline void add(int x,int y,int z){a[++tot]=y;c[tot]=z;ne[tot]=fi[x];fi[x]=tot;}
queue<pair<int,int> >q;
inline void get_fr(int x,int s){
    fr[x]=s;
    for (int i=fi[x];i;i=ne[i])if (!fr[a[i]]){
        d[s]=__gcd(d[s],c[i]);
        get_fr(a[i],s);
    }
}
inline void bfs(int s){
    q.push(pr(s,0));f[s][0]=1;
    while (!q.empty()){
        int u=q.front().first,v=q.front().second;
        q.pop();
        fr[u]=s;
        for (int i=fi[u];i;i=ne[i]){
            int nv=(v+c[i]/d[s])&1;
            if (!f[a[i]][nv]) f[a[i]][nv]=1,q.push(pr(a[i],nv));
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&qn);
    for (int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
     
    for (int i=1;i<=n;++i) if (!fr[i]) get_fr(i,i),bfs(i);
    for (int i=1;i<=qn;++i){
        scanf("%d%d%d",&x,&y,&k);
        if (fr[x]!=fr[y]) {puts("NIE");continue;}
        int nd=__gcd(d[fr[x]],k);
        if ((k/nd&1)||f[x][0]&&f[y][0]||f[x][1]&&f[y][1]) puts("0");else printf("%d\n",nd);
    }
    return 0;
}
```
*****



## C
### Problem description
>求一个字符串中的gcd子序列个数.

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
>主要是前缀和优化
http://www.hzxjhs.com:83/contest/775/problem/3/solution

### Code
```cpp
#include<cstdio>
long long n,i,j,q,mo=1,r[100000],l[100000],f[100000][4]; 
char s[100000];
int main()
{
	scanf("%s",&s);scanf("%d",&q);
	for (i=1;i<=32;i++)mo*=2;
	for (i=1;i<=q;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		/*for (j=l[i]-1;j<=r[i];j++)f[j][1]=f[j][2]=f[j][3]=0;
		for (j=l[i];j<=r[i];j++)
		{
			f[j][1]=f[j-1][1];f[j][2]=f[j-1][2];f[j][3]=f[j-1][3];
			if (s[j-1]=='g')f[j][1]++;
			if (s[j-1]=='c')f[j][2]++;
			if (s[j-1]=='d')f[j][3]++;
			
		}
		long long ans=f[r[i]][1]*f[r[i]][2]*f[r[i]][3];
		printf("%lld\n",ans);*/
		long long tot=0,tot2=0,ans=0;
		for (j=l[i];j<=r[i];j++)
		{
			if (s[j-1]=='g')
			{
				tot++;tot%=mo;
			}
			if (s[j-1]=='c')
			{
				tot2+=tot;tot2%=mo;
			}
			if (s[j-1]=='d')
			{
				ans+=tot2;ans%=mo;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
```
*****


