[比赛链接](http://www.hzxjhs.com:83/contest/781)

# 比赛中解决的问题
## A
### Problem description
>给出正整数n求出最小的正整数m,使n*m只含有1和0.

### Data Limit：m<= 1e5 n*m<=1e8 Time Limit: 1s

### Solution
>签到题,爆搜m即可

### Code
```cpp
#include<cstdio>
long long n,i,j,m,t,tt;
int main()
{
	scanf("%lld",&n);
	bool bo=false;
	for (i=1;i<=10000;i++)
	{
		tt=n*i;bool boo=true;
		while (tt>0)
		{
			if (tt%10>=2)
			{
				boo=false;break;
			}else tt=tt/10;
			//m=i;bo=true;
		}
		if (boo)
		{
			m=i;bo=true;
		}
		if (bo)break;
	}
	if (bo)printf("%lld\n",m);else puts("NO");
	return 0;
}
```
*****


## B
### Problem description
>给出n和n个正整数a[i],对于每个i,求出所有大于i且a[j]%a[i]=k的j的数量.
(a[i]<=m)
### Data Limit：n <=270000 m<=130000  Time Limit: 2.4s
### Solution
>由于a[i]的值域很小,那么我们可以求出每个值有几个,从第一个开始,求出所有符合题意的值,把个数相加即为此时的答案
但是这个最大复杂度是n*m,但还是Ac了.
所以应该从后向前扫,对于每个值减k后分解因数即可,这样是n*sqrt(m)的.(由于懒,这个就不打了,贴个原来的吧)
### Code
```cpp
#include<cstdio>
int n,i,j,m,k,max=-1;
int a[1000000],b[1000000];
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
		if (a[i]>max)max=a[i];
	}
	for (i=1;i<=n;i++)
	{
		b[a[i]]--;
		int t=k,ans=0;
		if (a[i]<=k)
		{
			printf("%d\n",0);continue;
		}
		while (t<=max)
		{
			ans=ans+b[t];
			t=t+a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
```
*****

# 赛后补题

## C
### Problem description
>一颗有N个点的树f(i,j)表示i到j的简单路径上边权第k小的边的边权
g(i,j)表示i到j的简单路径上边的数目.
求g(i,j)=l的(i,j)的最小的f[i,j]


### Data Limit：n <= 1e5 l<=50  Time Limit: 1s

### Solution
>二分答案,然后用dp判断此情况是否可行(f[i,j]表示从i开始的长为j的路径权值大于mv的最小个数)

### Code
```cpp
#include<cstdio>
const int N=300000;
int n,l,i,j,k,top=0,ans=1e9,x,y,z;
int a[N],c[N],first[N],next[N],last[N],q[1000000][4],ll[N],f[5000010][60];
bool bo[N];
int min(int a,int b)
{
    if (a>b)return b;else return a;
}
void add(int x,int y,int z)
{
    top++;a[top]=y;c[top]=z;
    if (first[x]==0)first[x]=top;else next[last[x]]=top;
    last[x]=top;
}
 void qsort(int l,int r)
  {
    int x,i,j;
    i=l; j=r; x=ll[l];
     while (i!=j)
     {
        while ((ll[j]>x)&&(i<j)) j--;
        if (i<j) {ll[i]=ll[j]; i++;}
        while ((ll[i]<x)&&(i<j))i++;
        if (i<j) {ll[j]=ll[i]; j--;}
     }
     ll[i]=x;  i++;j--;
     if (j>l) qsort(l,j);
     if (r>i)qsort(i,r);
  }
bool dfs(int x,int fa,int mv)
{
    f[x][0]=0;int p;
    for (p=1;p<=l;p++)f[x][p]=1e9;
    int i=first[x];
    while (i!=0)
    {
            if (a[i]!=fa){
        if (dfs(a[i],x,mv)) return 1;
        for (int p=0;p<l;++p)
        if (f[a[i]][p]+f[x][l-p-1]+(c[i]>mv)<=l-k) return 1;
        for (int p=0;p<l;++p)
        f[x][p+1]=min(f[x][p+1],f[a[i]][p]+(c[i]>mv));
    }
    i=next[i];
    }
 
    return 0;
}
bool check(int x)
{
    return dfs(1,0,x);
}
int main()
{
    scanf("%d%d%d",&n,&l,&k);
    for (i=1;i<=n-1;i++)
    {
        scanf("%d%d%d",&x,&y,&ll[i]);
        add(x,y,ll[i]);
        add(y,x,ll[i]);
    }
    qsort(1,n-1);
    ans=1e9;
    for (int l=1,r=n-1,mid;l<=r;mid=(l+r)>>1,check(ll[mid])?ans=ll[mid],r=mid-1:l=mid+1);
    printf("%d",ans);
    return 0;
}
```
*****
