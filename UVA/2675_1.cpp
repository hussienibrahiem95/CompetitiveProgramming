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
int n;
int dp[1001][1001];
int a[1005], p[1005];
int cum[1001];
int solve(int idx,int last){
	if (idx == n){
		return 0;
	}
	if (dp[idx][last] != -1){
		return dp[idx][last];
	}
	int ret = 1e9,cost=10;
	if (last){
		cost += (cum[idx] - cum[last - 1]);
	}
	else {
		cost += cum[idx];
	}
	cost *= p[idx];
	ret = min(ret, solve(idx + 1, idx + 1) + cost);
	if (idx !=n-1)
		ret = min(ret, solve(idx + 1, last));
	return dp[idx][last]=ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		clr(dp, -1);
		clr(cum, 0);
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> p[i];
			if (i)
				cum[i] += a[i] + cum[i - 1];
			else {
				cum[i] += a[i];
			}
		}
		cout << solve(0,0) << endl;
	}
}