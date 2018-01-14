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
const int N = 1000 + 20;
int dp[N][N][11][2];
int n, m;
string s, t;
int solve(int i, int j, int k, int prev){

	if (k < 0)
		return -1e9;
	if (i == n || j == m){
		if (k == 0)
			return 0;
		return -1e9;
	}
	int &ret = dp[i][j][k][prev];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	if (s[i] == t[j]){
		// first take sub string
		if (prev == 1){
			ret = max(ret, 1 + solve(i + 1, j + 1, k, 1));
		}

		ret = max(ret, 1 + solve(i + 1, j + 1, k - 1, 1));

	}

	ret = max(ret, solve(i + 1, j, k, 0));
	ret = max(ret, solve(i, j + 1, k, 0));
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	clr(dp, -1);
	int k;
	cin >> n >> m >> k;
	cin >> s >> t;
	cout << solve(0, 0, k, 0) << endl;
}