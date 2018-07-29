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
const int N = 1e5 + 20;
int dp[101][101], n, k, a[51];
int solve(int i, int j){
	if (i + 1 == j){
		return 0;
	}
	int &ret = dp[i][j];
	if (ret != -1){
		return ret;
	}
	ret = 1e9;
	for (int k = i + 1; k <= j; k++){
		int l = solve(i, k);
		int r = solve(k, j);
		ret = min(ret, l + r + a[j] - a[i]);
	}
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	while (cin >> n){
		if (n == 0){
			break;
		}
		cin >> k;
		clr(dp, -1);
		for (int i = 1; i <= k; i++){
			cin >> a[i];
		}
		a[++k] = n;
		cout << "The minimum cutting is " << solve(0, k) << "." << endl;
	}
}