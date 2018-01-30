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
const int N = 510 + 20;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	cin >> n;
	vector<pair<int, int>>p(n);
	map<int, int>vals, sum_val;
	map<int, vector<int>>data;
	int sumall = 0;
	for (int i = 0; i < n; i++){
		cin >> p[i].first;
	}
	for (int i = 0; i < n; i++){
		cin >> p[i].second;
		vals[p[i].first]++;
		sum_val[p[i].first] += p[i].second;
		sumall += p[i].second;
		data[p[i].first].push_back(p[i].second);
	}
	map<int, int, std::greater<int>>hv;
	int ans = 1e9;
	for (auto it : vals){
		int sum = 0;
		int ned = it.second - 1;
		for (auto it2 : hv){
			if (ned <= 0){
				break;
			}
			if (ned <= it2.second){
				sum += (ned * it2.first);
				ned = 0;
				break;
			}
			else {
				sum += (it2.second*it2.first);
				ned -= it2.second;
			}
		}
		for (int i = 0; i < data[it.first].size(); i++){
			int num = data[it.first][i];
			hv[num]++;
		}
		ans = min(ans, sumall - (sum + sum_val[it.first]));
	}
	cout << ans << endl;
}