# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>	

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
    //����
	for (i = 0; i < sz-1; i++)
	{
		//һ��ð������
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ð������ʵ��
	bubble_sort(arr,sz);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);

	}
	return 0;
}