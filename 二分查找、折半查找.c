#include<stdio.h>
int k = 6;
int arr[] = { 1, 2, 3, 4, 5, 6, 9, 10, 11 };
int main()
{
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;

	for (; left <= right;)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else if (arr[mid] == k)
		{
			printf("�ҵ���,�±�Ϊ%d��ֵΪ%d��", mid, arr[mid]);
			break;
		}
	}
	if (right < left)
		printf("�Ҳ�����");
	return 0;
}