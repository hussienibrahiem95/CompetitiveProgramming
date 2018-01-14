#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	int ll;
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
const int N = 200 + 20;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int >>>grr(m);
	for (int i = 0; i < m; i++){
		ll u, v, cost;
		cin >> grr[i].first >> grr[i].second.first;
		grr[i].second.first *= -1;
		grr[i].second.second = i;

	}
	ll one = 1;
	sort(all(grr));
	queue<pair<int, int>>oth;
	vector<pair<int, int >>ans(m);
	for (int i = 0; i < m; i++){
		if (grr[i].second.first == -1){
			ans[grr[i].second.second] = { one, one + 1 };
			one++;
			for (int j = 1; j < m&&j < one - 1 && oth.size()<m; j++){
				oth.push({ j, one });
			}
		}
		else {
			if (oth.empty()){
				cout << -1 << endl;
				return 0;
			}
			ans[grr[i].second.second] = { oth.front().first, oth.front().second };
			oth.pop();
		}
	}
	for (int i = 0; i < m; i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}