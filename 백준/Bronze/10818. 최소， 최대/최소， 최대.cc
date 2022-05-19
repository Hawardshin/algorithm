#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	int max, min;
	int arr1;
	scanf("%d", &arr1);
	max = arr1;
	min = arr1;
	for (int i = 1; i < a; i++)
	{
		scanf("%d", &arr1);

		if (max < arr1)
			max = arr1;
		if (min > arr1)
			min = arr1;
	}
	printf("%d %d", min ,max);
	return (0);
}