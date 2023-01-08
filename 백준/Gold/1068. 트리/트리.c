#include<stdio.h>

int count = 0;
dfs(int now_node, int* node, int nodenum,int root)
{
	int check = 0;
	for (int i = 0; i < nodenum; i++)
	{
		if (now_node == node[i])
		{
			check++;
			//printf("i: %d\n", i);
			dfs(i, node, nodenum,root);
		}
	}
	if (check == 0)//now_node>=0&&now_node!=root&&
		count++;
	
}

int main()
{
	int node[50];
	int nodenum,ignore_node;
	int root=100;
	scanf("%d", &nodenum);
	for (int i = 0; i < nodenum; i++)
	{
		scanf("%d", &node[i]);
		if (node[i] == -1)
			root = i;
		
	}
	scanf("%d", &ignore_node);
	//input
	node[ignore_node] = -2;
	if (ignore_node == root||root==100)
	{
		printf("0");
		return(0);
	}
	dfs(root, node, nodenum,root);
	printf("%d", count);
}