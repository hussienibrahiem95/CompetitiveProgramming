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
	while (cin >> n&&n){
		map<vector<int>, int>mp;
		int mx = 0;
		for (int i = 0; i < n; i++){
			vector<int>v(5);
			for (int i = 0; i < 5; i++){
				cin >> v[i];
			}
			sort(all(v));
			mp[v]++;
			mx = max(mx, mp[v]);
		}
		int ans = 0;
		for (auto it : mp){
			ans += (it.second == mx) ? mx:0;
		}
		cout << ans<< endl;
	}
}