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
	char a[100] = { 0 };				//�߾��ȳ˷���˼·�ǳ˷���ʽ���㣬ÿ�εĽ��������
	char b[100] = { 0 };				//���Ŵ浽sum�������������
	scanf("%s %s", a, b);
	int aw;//λ��
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
	//�߾��ӷ���
	int i1;
	int A1, B1;
	int alen1;
	int blen1;
	int sum0 = 0;//ÿλ��ӵĺ�
	int mid1 = 0;
	char ans[100] = { 0 };
	for (bw = blen-1; bw >=0; bw--)				//��ʽ��������������һλ��ʼ
	{
		//��ʼ��sum1
		char sum1[100] = { 0 };
		i = 0 + j;//ÿ�λ�������ʱ��һλ
		for (aw = alen - 1; aw >= 0; aw--,i++)	//��ʽ�����ÿһλ��ȫ������Ӻüӵ�sum1�У�Ȼ�����ӵ�sum��
		{		
			re = ((int)a[aw] - 48) * ((int)b[bw] - 48)+ris;//<ÿ��������˵Ľ��>
			ris = 0;							//
			if (re > 9)
			{
				ris = re/10;					//ris ��һ�γ˻����ھ�����λ
				re -= ris*10;					//���¸�λ
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
		//����Ϊһλ��
		//����߾���һ��

		
		alen1 = strlen(sum1);
		blen1 = strlen(sum);				//�ϵ����ֱ�ӿ���λ����˵ĳ˷����
		for (i1 = j; i1 < 100; i1++)
		{
			sum0 = 0;
			A1 = (int)(sum1[i1] - 48);		//����ʱ���Զ�ת��
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
			sum0 = A1 + B1 + mid1;			//�ϵ㿴��ʽ��һ���ȴ��˽�ȥ
			mid1 = 0;				//�����ٳ�ʼ��
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
				if (sum1[i1+1] != '\0')								//����һλ
				{
					sum[i1 + 1] = (char)((int)sum1[i1+1]+mid1);
					if (sum[i1 + 1] > '9')							//r����
					{
						sum[i1 + 2] = (char)(((int)sum[i1 + 1]-48)/10+48);
						sum[i1 + 1] = (char)(((int)sum[i1 + 1]-48)%10+48);			//10 %10==0�ˣ�Ҫ��1�ģ�����������
						
						break;
					}
				}
				else if (sum1[i1 + 1] == '\0' && mid1 == 1)
				{
					sum[i1 + 1] = '1';
				}
				if (sum1[i1 + 2] != '\0')							//������λ
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