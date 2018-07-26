#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
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
	int n, m;
	cin >> n >> m;
	map<string, int>mp;
	for (int i = 0; i < n; i++){
		string x;
		int cost;
		cin >> x >> cost;
		mp[x] += cost;
	}
	while (m--){
		string x;
		ll ans = 0;
		while (cin >> x&&x != "."){
			ans += mp[x];
		}
		cout << ans << endl;
	}
}