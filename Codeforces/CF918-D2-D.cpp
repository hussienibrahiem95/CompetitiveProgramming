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
int dp[200][200][300];
char vals[120][120];
vector<vector<int>>gr(200);
int solve(int i, int j, char who){
	int &ret = dp[i][j][who];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	for (int k = 0; k < gr[i].size(); k++){
		int nxt = gr[i][k];
		char val = vals[i][nxt];
		if (who <= val){
			int can = solve(j, nxt, val);
			if (!can){
				ret = 1;
				break;
			}
		}
	}
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n, m;
	cin >> n >> m;
	clr(dp, -1);
	for (int i = 0; i < m; i++){
		char ch;
		int x, y;
		cin >> x >> y >> ch;
		x--, y--;
		gr[x].push_back(y);
		vals[x][y] = ch;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int win = solve(i, j, 'a');
			if (win){
				cout << 'A';
			}
			else {
				cout << 'B';
			}
			if (j == n - 1){
				cout << "\n";
			}
		}
	}
}