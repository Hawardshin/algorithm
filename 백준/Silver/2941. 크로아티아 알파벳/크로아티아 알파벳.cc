#include<stdio.h>
#include<string.h>
int main()
{
	char arr[300];
	scanf("%s", arr);
	int count = 0;

	int size = strlen(arr);
	for (int i = 0; i < size; i++)
	{

		if (arr[i] == 'c' && (arr[i + 1] == '=' || arr[i + 1] == '-'))
			i++;
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=')
			i += 2;
		else if (arr[i] == 'd' && arr[i + 1] == '-')
			i++;
		else if (arr[i] == 'l' && arr[i + 1] == 'j')
			i++;
		else if (arr[i] == 'n' && arr[i + 1] == 'j')
			i++;
		else if (arr[i] == 's' && arr[i + 1] == '=')
			i++;
		else if (arr[i] == 'z' && arr[i + 1] == '=')
			i++;
		count++;
	}
	printf("%d", count);
}