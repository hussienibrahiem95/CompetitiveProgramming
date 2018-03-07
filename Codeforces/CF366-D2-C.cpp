#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define __builtin_popcount __popcnt
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
int n;
int mx = -1, k;
int a[101], b[101];
int dp[101][100001];
int solve(int i, int sum1){
	if (i == n){
		if (sum1 == 0)
			return sum1;
		return -1e9;
	}
	int &ret = dp[i][sum1];
	if (ret != -1){
		return ret;
	}
	ret = solve(i + 1, sum1);
	ret = max(ret, solve(i + 1, sum1 + (a[i] - b[i] * k)) + a[i]);
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}
	clr(dp, -1);
	int ans = solve(0, 0);
	if (!ans)
		ans = -1;
	cout << ans << endl;
}