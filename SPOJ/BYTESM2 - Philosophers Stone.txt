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
const int N = 100 + 20;
int a[N][N];
int dp[N][N];
int n, m;
/***You***Can***Do***It***/
 
int solve(int i, int j){
	if (i == n - 1){
		return a[i][j];
	}
	if (dp[i][j] != -1){
		return dp[i][j];
	}
	int ch1 = a[i][j] + solve(i + 1, j);
	int ch2 = 0;
	int ch3 = 0;
	if (j + 1 < m){
		ch2 = a[i][j] + solve(i + 1, j + 1);
	}
	if (j - 1 >= 0){
		ch3 = a[i][j] + solve(i + 1, j - 1);
	}
	return dp[i][j] = max(ch1, max(ch2, ch3));
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		clr(dp, -1);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int mx = 0;
		for (int i = 0; i < m; i++){
			mx = max(mx, solve(0, i));
		}
		cout << mx << endl;
	}
}