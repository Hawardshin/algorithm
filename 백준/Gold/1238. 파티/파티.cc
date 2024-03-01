// 3. https://www.acmicpc.net/problem/1238

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define COST first
#define WAY second
#define INF 0x3f3f3f3f
using namespace std;
int n,m,x;
vector<pair<int,int>> ways1[1001];
int dp1[1001]; // 오는길
int dp2[1001]; //가는길
vector<pair<int,int>>ways2[1001];

void dijkstra1(int start){
	dp1[start] =0;
	priority_queue<pair<int,int> > pq;
	pq.push({0, start});
	while (!pq.empty()){
		int dis = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dp1[cur] < dis) continue;
		for(int i=0;i< ways1[cur].size();i++){
			int nxt = ways1[cur][i].WAY;
			int ndis = dis + ways1[cur][i].COST;
			
			if (ndis < dp1[nxt]){
				dp1[nxt] = ndis;
				pq.push({-ndis, nxt});
			}
		}
	}
}

void dijkstra2(int start){
	dp2[start] =0;
	priority_queue<pair<int,int> > pq;
	pq.push({0, start});
	while (!pq.empty()){
		int dis = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dp2[cur] < dis) continue;
		for(int i=0;i< ways2[cur].size();i++){
			int nxt = ways2[cur][i].WAY;
			int ndis = dis + ways2[cur][i].COST;
			
			if (ndis < dp2[nxt]){
				dp2[nxt] = ndis;
				pq.push({-ndis, nxt});
			}
		}
	}
}

int max_s,max_i;

int main(){
	cin >> n >> m >> x;
	int a,b,t;
	memset(dp1,0x3f, sizeof(dp1));
	memset(dp2,0x3f, sizeof(dp2));
	for(int i=0;i<m;i++){
		cin >>a >>b>>t;
		ways1[a].push_back({t,b});
		ways2[b].push_back({t,a});
	}
	dijkstra1(x);
	dijkstra2(x);
	for(int i=1;i<=n;i++){
		max_s = max(max_s,dp1[i]+dp2[i]);
	}
	cout << max_s <<"\n";
}