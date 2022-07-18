# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//有序数列中的二分查找
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	printf("请输入要查找的数：>");
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
			printf("找到了，下标为：%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("没找到\n");
	}
	return 0;
}


//数列中的遍历查找(最基础的查找，也是效率最低下的查找)
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	int i = 0;
	printf("请输入要查找的数：>");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0;i < sz;i++)
	{
		if (arr[i] == k)
		{
			printf("找到了，下标为：%d\n", i);
			break;
		}
	}
	if (i == sz)
	{
		printf("没找到\n");
	}
	return 0;
}
*/