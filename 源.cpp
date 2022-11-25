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
	char a[100] = { 0 };				//高精度乘法，思路是乘法竖式计算，每次的结果加起来
	char b[100] = { 0 };				//倒着存到sum里，最后函数逆序输出
	scanf("%s %s", a, b);
	int aw;//位数
	int bw;//
	int alen = strlen(a);
	int blen = strlen(b);
	int i, j = 0;
	int re;
	int ris = 0;
	char sum[100] = { 0 };
	//for (i = 0; i < 100; i++)
	//{
	//	sum[i] = '0';
	//}
	//高精加法滴
	int i1;
	int A1, B1;
	int alen1;
	int blen1;
	int sum0 = 0;//每位相加的和
	int mid1 = 0;
	char ans[100] = { 0 };
	for (bw = blen-1; bw >=0; bw--)				//竖式中下面的数的最后一位开始
	{
		//初始化sum1
		char sum1[100] = { 0 };
		i = 0 + j;//每次换个数乘时进一位
		for (aw = alen - 1; aw >= 0; aw--,i++)	//竖式上面的每一位，全部乘完加好加到sum1中，然后最后加到sum中
		{		
			re = ((int)a[aw] - 48) * ((int)b[bw] - 48)+ris;//<每两个数相乘的结果>
			ris = 0;							//
			if (re > 9)
			{
				ris = re/10;					//ris 上一次乘积大于玖进的位
				re -= ris*10;					//留下个位
				sum1[i] = (char)(re + 48);		
			}
			else
			{				
				sum1[i] = (char)(re + 48);
			}
			if (aw == 0 && ris>0)
			{
				sum1[i + 1] = (char)(ris+48);
				ris = 0;
			}
		}
		//以上为一位乘
		//下面高精加一下

		
		alen1 = strlen(sum1);
		blen1 = strlen(sum);				//断点可以直接看两位数相乘的乘法结果
		for (i1 = j; i1 < 100; i1++)
		{
			sum0 = 0;
			A1 = (int)(sum1[i1] - 48);		//减的时候自动转啦
			B1 = (int)(sum[i1] - 48);
			if (sum1[i1] == '\0')
			{
				sum0 = B1 + mid1;
			}
			else if (sum[i1] == '\0')
			{
				sum0 = A1 + mid1;
			}
			else
			sum0 = A1 + B1 + mid1;			//断点看竖式第一行先存了进去
			mid1 = 0;				//用了再初始化
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
			if (i1 >= alen1 - 1 && i1 >= blen1 - 1)
			{
				if (sum1[i1+1] != '\0')								//额外一位
				{
					sum[i1 + 1] = (char)((int)sum1[i1+1]+mid1);
					if (sum[i1 + 1] > '9')							//r若超
					{
						sum[i1 + 2] = (char)(((int)sum[i1 + 1]-48)/10+48);
						sum[i1 + 1] = (char)(((int)sum[i1 + 1]-48)%10+48);			//10 %10==0了，要进1的！！！！！！
						
						break;
					}
				}
				else if (sum1[i1 + 1] == '\0' && mid1 == 1)
				{
					sum[i1 + 1] = '1';
				}
				if (sum1[i1 + 2] != '\0')							//额外两位
				{
					sum[i1 + 2] = sum1[i1 + 2];
				}
				break;
			}
			
		}
		j++;
	}
	my_reverse(sum);
}