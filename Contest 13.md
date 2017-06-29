## A
### Problem description
> 暴力模拟即可
### Solution
模拟模拟！
```cpp
#include<cstdio>
#include<string.h>
using namespace std;
long long cache,longn,left,right;
char s[1005000];
int main()
{
	scanf("%s",s);
	longn=strlen(s);
	for(int i=0;i<=longn-1;i++) if (s[i]=='^')
	{
		cache=i;
		break;
	}
	left=0;
	right=0;
	for(int i=0;i<cache;i++) if(s[i]-48<10) left+=(s[i]-48)*(cache-i);
	for(int i=cache+1;i<=longn-1;i++) if(s[i]-48<10) right+=(s[i]-48)*(i-cache);
	if(left==right)
	{
		printf("balance");
	}
	if(left>right)
	{
		printf("left");
	}
	if(right>left)
	{
		printf("right");
	}
	return 0;
}
```
## B
### Problem description
> 并不知道怎么做出来的反正AC了
### Solution
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int ans,cache[120],a,n,s1,s2,s3;
int main()
{
	for(int i=0;i<=119;i++) cache[i]=0;
	scanf("%d%d",&a,&n);
	for(int i=1;i<=n;i++) 
	{
	scanf("%d%d%d",&s1,&s2,&s3);
	cache[s1]=cache[s1]-s3;
	cache[s2]=cache[s2]+s3;
    }
    ans=0;
    for(int i=1;i<=a;i++)
    if(cache[i]>0) ans=ans+cache[i];
    cout<<ans;
	return 0;
}
```
