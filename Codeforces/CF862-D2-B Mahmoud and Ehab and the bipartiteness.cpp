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
const int N = 1e5 + 20;
vector<vector<int>>gr(N);
int vis[N];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	queue<int>q;
	vis[1] = 1;
	q.push(1);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i = 0; i < gr[node].size(); i++){
			int nxt = gr[node][i];
			if (!vis[nxt]){
				if (vis[node] == 1){
					vis[nxt] = 2;
				}
				else {
					vis[nxt] = 1;
				}
				q.push(nxt);
			}
		}
	}
	int sz1=0, sz2 = 0;
	for (int i = 1; i <= n; i++){
		if (vis[i] == 1){
			sz1++;
		}
		else {
			sz2++;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		if (vis[i] == 1){
			ans += (sz2 - (int)gr[i].size());
		}
	}
	cout << ans << endl;

}