# 比赛记录

[比赛链接](https://www.codeforces.com)
## A
### Problem description
> 俩人被一怪物追着打，俩人会叫，如果一起叫，他们就GG了。一个人在B秒叫，隔了A秒又叫，一个人在D秒叫，隔了C秒又叫
### Solution
```cpp
#include<cstdio>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int ceng=0; //该变量用来判断是否会GG
	while(b!=d)
	{
		if(b<d) b+=a; //时间流逝
		else(d+=c);
		ceng++;
		if(ceng>1000000) //1000000是一个估计的数字，估计叫了1000000次后也不会被弄死了
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d",b);
	return 0;
}
```
## B
### Problem description
> 在n个平行宇宙中有n的A和n个B，一个是好的一个是坏的。他们分成几个小组，如果一个小组中人可能全是坏的那么就GG
### Solution
首先明确，如果一个小组中有同一个宇宙中的A和B那么久不会GG，所以只要判断一个小组中是否有一个宇宙的A和B，若没有就GG
```cpp
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int n,m,pdd[10200],pddd[10200];//判断变量
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int cache;
		memset(pdd,0,sizeof(pdd));
		memset(pddd,0,sizeof(pddd));
		scanf("%d",&cache);
		if(cache==1)
		{
			printf("YES");
			return 0;
		}
		for(int k=1;k<=cache;k++)
		{
			int cache1;
			scanf("%d",&cache1);
			if (cache1>0)pdd[cache1]=1; else pddd[0-cache1]=1; //各自出现
		}
		int pd=0;
		for(int k=1;k<=n;k++) if ((pdd[k]==1&&pddd[k]==1)) {pd=1;break;} //同时出现则下一条语句重新来，不然输出YES然后结束程序
		if (pd) continue;
		printf("YES");
		return 0;
	}
	printf("NO");
	return 0;
}
```
