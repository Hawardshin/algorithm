int main()
{
	int input;
	int result;
	scanf("%d", &input);
	char arr[50];
	int len;
	for (int i = 0; i < input; i++)
	{
		result = 0;
		scanf("%s", arr);
		len=strlen(arr);
		for (int j = 0; j < len; j++)
		{
			if (arr[j] == '(')
				result++;
			else if(arr[j]==')')
				result--;
			if (result == -1)
				break;
		}
		if (result == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}