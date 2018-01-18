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
const int N = 300 + 20;
int money, c;
int prices[22][22];
int dp[N][N];
int solve(int m, int g){
	if (m < 0){
		return -1e9;
	}
	if (g == c){
		return money - m;
	}
	int &ret = dp[m][g];
	if (ret != -1){
		return ret;
	}
	ret = -1e9;
	for (int i = 1; i <= prices[g][0]; i++){
		ret = max(ret, solve(m - prices[g][i], g + 1));
	}
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		cin >> money >> c;
		for (int i = 0; i < c; i++){
			cin >> prices[i][0]; // indicate the number of different models
			for (int j = 1; j <= prices[i][0]; j++){
				cin >> prices[i][j];
			}
		}
		clr(dp, -1);
		int ans = solve(money, 0);
		if (ans < 0){
			cout << "no solution" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}