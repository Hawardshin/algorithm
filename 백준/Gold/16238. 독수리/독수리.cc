#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;
#define IDX first
#define FOOD second
/*0이 되는경우를 제거해야한다.(n은 겨우 1000밖에 안된다.)
배열이 있고 이전의 값이 1인 경우 줄어들 숫자의 갯수중 제외를 해준다.
변수 : 현재 독수리 위치 인덱스 ==
날아갈 독수리 수 = 현재 독수리 인덱스 - 그 앞에 있는 1이 아닌 독수리 칸

// */
// int arr[1001];
// int sorting[1001];
int eat_sum;

void	print_vec(vector <pair <int, int > > &a,int n)
{
	cout << " \n----------------------------\n";
	for (int i=0; i < n; i++)
	{
		cout << "idx : " << a[i].IDX << "  FOOD : " << a[i].FOOD << "\n";
	}
}
bool cmp_input(const pair <int , int >& a, const pair <int, int>& b)
{
	return (a.FOOD < b.FOOD);
}

bool cmp_input2(const pair <int , int >& a, const pair <int, int>& b)
{
	return (a.FOOD > b.FOOD);
}

int where_to_go(const vector <pair<int, int> > &a, int now, int n)
{
	while (now < n)
	{
		if (a[now].FOOD >= n - now)
			return (now);
		else
			now++;
	}
	return (n);
}

void	print_my_vector(const vector <pair<int ,int > > &a, int now)
{
	cout << "now idx :: " << now << "  vec idx:: " << a[now].IDX << " vec food:: " << a[now].FOOD << "\n";
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int n;
	int now = 0;

	vector<pair <int ,int > >arr;
	cin >> n;
	//없어지는 음식 수 : n - 인덱스 위치
	//핵심 로직 : 없어지는 음식수 <=(등호상관 없다.) 먹을 음식 수
	//현재 상태에서 가장 가까운 먹을거로 이동
	int tmp;
	for(int i=0; i< n;i++)
	{
		cin >> tmp;
		arr.push_back({i,tmp});//{idx, input}
	}
	// print_vec(arr, n);
	// if (arr[now].FOOD >= n)
	// 	eat_sum += arr[now].FOOD;
	// now++;
	sort(arr.begin(), arr.end(), cmp_input2);
	for (int i=0; i < n; i++)
	{
		if (arr[i].FOOD <=0)
			break;
		eat_sum += arr[i].FOOD;
		for (int j =i; j < n; j++)
		{
			arr[j].FOOD--;
		}
	}
	cout << eat_sum << "\n";
	// if (arr[0].FOOD != 0 && arr[1].FOOD == 0)
	// {
	// 	eat_sum = arr[0].FOOD;
	// 	cout << eat_sum << "\n";
	// 	return (0);
	// }
	// while (now < n)
	// {
	// 	sort(arr.begin() + now, arr.end());// 인덱스 순서로 다시 정렬
	// 	// print_vec(arr, n);
	// 	now = where_to_go(arr, now, n);
	// 	eat_sum += arr[now].FOOD;
	// 	// print_my_vector(arr, now);
	// 	arr[now].FOOD = 0;
	// 	//하루가 지났으니 배열내의 모든 값들을 다시 1씩 뺴준다
	// 	for (int i=0; i < n; i++)
	// 		arr[i].FOOD--;
	// 	sort(arr.begin() + now, arr.end(),cmp_input);//음식 순으로 정렬
	// 	// print_vec(arr, n);
	// 	while (now < n && arr[now].FOOD <= 0)
	// 		now++;//음식이 0이 된 경우 배제하는 것이다.
	// }
	// sort(arr.begin(), arr.end(), cmp_input2);
	// for (int i=0; arr[i].FOOD > 0 && i < n; i++)
	// {
	// 	eat_sum += arr[i].FOOD;
	// 	arr[i+1].FOOD--;
	// }
	// cout << eat_sum << "\n";
	// cout << "eat " << eat_sum << "\n";
	// sort(sorting, sortng+ n, cmp);
	// for (int i=0; i < n; i++)
	// 	cout << sorting[i] << " ";
	// int idx = 0;
	// while (idx < n)
	// {
	// 	if (arr[idx] > idx)
	// }


}
