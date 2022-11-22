#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<string.h>
void my_reverse(char bns[])
{
	int n = strlen(bns) - 1;
	int i;
	char ans[100] = { 0 };
	for (i = 0; i < n + 1; i++)
	{
		ans[i] = bns[i];
	}
	int lef = 0;
	int rit = n;
	char tmp;
	while (lef <= rit)
	{
		tmp = ans[lef];
		ans[lef] = ans[rit];
		ans[rit] = tmp;
		lef++;
		rit--;
	}
	printf("%s\n", ans);
}
int main()
{
	char a[100] = { 0 };
	char b[100] = { 0 };
	scanf("%s %s", a, b);
	int aw;
	int bw;
	int alen = strlen(a);
	int blen = strlen(b);
	int i, j = 0;
	int re;
	int ris;
	char sum1[100] = { 0 };
	char sum[100] = { 0 };
	//高精加法滴
	int i1;
	int A1, B1;
	int alen1;
	int blen1;
	int sum0 = 0;
	int mid1 = 0;
	char ans[100] = { 0 };
	for (bw = blen-1; bw >=0; bw--)
	{
		i = 0 + j;
		for (aw = alen - 1; aw >= 0; aw--,i++)
		{
			ris = 0;
			re = ((int)a[aw] - 48) * ((int)b[aw] - 48)+ris;
			if (re > 9)
			{
				ris = 1;
				re -= 10;
				sum1[i] = (char)(re + 48);
			}
			else
			{				
				sum1[i] = (char)(re + 48);
			}
			if (aw == 0 && ris == 1)
			{
				sum1[i + 1] = '1';
			}
		}
		//以上为一位乘
		//下面高精加一下
		alen1 = strlen(sum1);
		blen1 = strlen(sum);
		for (i1 = 0; i1 < 100; i1++)
		{
			sum0 = 0;
			A1 = (int)(sum1[i1] - 48);
			B1 = (int)(sum[i1] - 48);
			sum0 = A1 + B1 + mid1;
			if (sum0 > 9)
			{
				mid1 = 1;
				sum0 -= 10;
				sum[i1] = (char)(sum0 + 48);
			}
			else
			{
				sum[i1] = (char)(sum0 + 48);
			}
			if (i1 > alen1 + 1 && i1 > blen1 + 1)
			{
				break;
			}
			mid1 = 0;
		}
		j++;
	}


	my_reverse(sum);
}