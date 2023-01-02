#include<stdio.h>

void ctoi(char* arr, int* ar,int m)
{
	for (int i = 0; i < m; i++)
	{
		ar[i] = arr[i] - 48;
		//printf("%d\n", ar[i + 1]);
	}
}
int cue[40000];
int front = 0;
int rear = 0;

void bfs(int y, int x,int (*map)[200],int xmax,int ymax)//bfs는 방향벡터 순서와도 관련이 있는가?
{
	int popx = x;
	int popy = y;
	while (front <= rear)
	{
		
		
		//printf("%d,%d :%d\n",popy,popx, map[popy][popx]);//x의 최대값과 y의 최대값을 넘어가는경우 비교가 제대로 이루어지지 않는다.
		
		if (popy<ymax-1&&map[popy + 1][popx] == 1)
		{
			map[popy + 1][popx] += map[popy][popx] ;
			cue[rear++] = (popy + 1) * xmax + popx;
		}
		if (0<popy &&map[popy - 1][popx] == 1)
		{
			map[popy - 1][popx] += map[popy][popx];
			cue[rear++] = (popy - 1) * xmax + popx;
		}
		if (popx<xmax-1&&map[popy][popx + 1] == 1)
		{
			map[popy][popx + 1] += map[popy][popx];
			cue[rear++] = (popy)*xmax + popx + 1;
		}
		if (0<popx&&map[popy][popx - 1] == 1)
		{
			map[popy][popx - 1] += map[popy][popx];
			cue[rear++] = (popy)*xmax + popx - 1;
		}
		popy = cue[front] / xmax;
		popx = cue[front] % xmax;
		//if (cue[front] % xmax == 0)
	//	{
		//	popx = xmax;
		//}
		front++;
	}
	//printf("%d")
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	char arr[200];
	int map[200][200] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr);
		ctoi(arr, map[i],m);
	}
	bfs(0, 0, map, m,n);
	printf("%d", map[n-1][m-1]);

}