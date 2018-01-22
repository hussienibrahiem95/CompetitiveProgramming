#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 20 + 20;
char a[N][N];
int vis[N][N];
int n, m, cnt;
char ch1;
bool valid(int i, int j){
	if (i < 0 || i >= n || vis[i][j] || a[i][j] != ch1){
		return 0;
	}
	return 1;
}
void dfs(int i, int j){
	if (!valid(i, j))
		return;
	vis[i][j] = 1;
	cnt++;
	dfs(i + 1, j);
	dfs(i - 1, j);
	if (j + 1 == m){
		dfs(i, 0);
	}
	else {
		dfs(i, j + 1);
	}
	if (j - 1 == -1){
		dfs(i, m - 1);
	}
	else {
		dfs(i, j - 1);
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	while (cin >> n >> m){
		clr(vis, 0);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int x, y;
		cin >> x >> y;
		ch1 = a[x][y];
		dfs(x, y);
		int mx = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i][j] == ch1&&!vis[i][j]){
					cnt = 0;
					dfs(i, j);
					mx = max(mx, cnt);
				}
			}
		}
		cout << mx << endl;
	}
}