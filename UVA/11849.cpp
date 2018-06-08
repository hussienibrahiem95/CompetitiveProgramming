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
	int n, m;
	while (cin >> n>>m&&n&&m){
		
		map<int, int>mp;
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			mp[a]++;
		}
		int ans = 0;
		for (int i = 0; i < m; i++){
			int a;
			cin >> a;
			if (mp[a]){
				ans++;
			}
		}
		cout << ans << endl;
	}
}