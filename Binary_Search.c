# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���������еĶ��ֲ���
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	printf("������Ҫ���ҵ�����>");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz-1;
	int left = 0;
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("û�ҵ�\n");
	}
	return 0;
}


//�����еı�������(������Ĳ��ң�Ҳ��Ч������µĲ���)
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	int i = 0;
	printf("������Ҫ���ҵ�����>");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0;i < sz;i++)
	{
		if (arr[i] == k)
		{
			printf("�ҵ��ˣ��±�Ϊ��%d\n", i);
			break;
		}
	}
	if (i == sz)
	{
		printf("û�ҵ�\n");
	}
	return 0;
}
*/