#include<stdio.h>

int N;
int Arr[1001];
int DP[1001];    // 앞에서부터 찾는 최장수열
int R_DP[1001];    // 뒤에서부터 찾는 최장수열

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (Arr[j] < Arr[i] && DP[i] < DP[j] + 1)
            {
                DP[i] = DP[j] + 1;
            }
        }
    }

    for (int i = N; i >= 1; i--)
    {
        R_DP[i] = 1;
        for (int j = N; j >= i; j--)
        {
            if (Arr[i] > Arr[j] && R_DP[j] + 1 > R_DP[i])
            {
                R_DP[i] = R_DP[j] + 1;
            }
        }
    }
    int Answer = 0;
    for (int i = 0; i <= N; i++)
    {
        if (Answer < DP[i] + R_DP[i] - 1) 
            Answer = DP[i] + R_DP[i] - 1;
    }
    printf("%d", Answer);

}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &Arr[i]);
	}
    Solution();
}