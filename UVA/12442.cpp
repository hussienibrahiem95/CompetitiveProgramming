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
const int N = 1e6 + 20;
int comp_num;
int vis[N];
int cnt = 0;
vector<vector<int>>gr(N);
void dfs(int node){
	vis[node] = comp_num;
	cnt++;
	for (auto nxt : gr[node]){
		if (vis[nxt] != comp_num){
			dfs(nxt);
		}
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t,nw=1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		gr.clear(); gr.resize(n+1);
		clr(vis, 0);
		for (int i = 0; i < n; i++){
			int u, v;
			cin >> u >> v;
			gr[u].push_back(v);
		}
		int mx = 0, ans = 1;
		for (int i = 1; i <= n; i++){
			if (!vis[i]){
				comp_num = i; cnt = 0;
				dfs(i);
				if (cnt>mx){
					mx = cnt;
					ans = i;
				}
			}
		}
		cout << "Case " << nw++<<": " << ans << endl;
	}
}