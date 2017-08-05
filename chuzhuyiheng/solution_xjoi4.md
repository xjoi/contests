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


## B
### Problem description
>给出一张图,求

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
> 

### Code
```cpp
```
*****

# 赛后补题

## C
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> 

### Code
```cpp
```
*****


## D
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
> 

### Code
```cpp
```
*****

## E
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> 

### Code
```cpp
```
