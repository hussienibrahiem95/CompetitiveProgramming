#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 1e6 + 20;
bool isprime(int x){
	if (x == 2){
		return 1;
	}
	if (x == 1 || x % 2 == 0){
		return 0;
	}
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0){
			return 0;
		}
	}
	return 1;
}
struct edge{
	int from, to, cost;
};
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n, m;
	ll cost = 0;
	cin >> n >> m;
	vector<edge>gr;
	for (int i = 1; i < n - 1; i++){
		edge e;
		e.from = i;
		e.to = i + 1;
		e.cost = 1;
		cost++;
		gr.push_back(e);
	}
	int sum = n - 1;
	for (int i = sum;; i++){
		if (isprime(i)){
			edge e;
			e.from = n - 1;
			e.to = n;
			e.cost = i - sum + 1;
			cost += e.cost;
			gr.push_back(e);
			break;
		}
	}
	cout << cost << " " << cost << endl;
	for (int i = 0; i < gr.size(); i++){
		cout << gr[i].from << " " << gr[i].to << " " <<
			gr[i].cost << endl;
	}
	int rem = m - n + 1;
	int idx1 = 1, idx2 = 3;
	while (rem--){
		cout << idx1 << " " << idx2 << " " << (int)1e9 << endl;
		idx2++;
		if (idx2 == n + 1){
			idx1++;
			idx2 = idx1 + 2;
		}
	}
}