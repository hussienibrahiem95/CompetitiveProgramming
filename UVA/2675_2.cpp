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
int dp[101];
int a[105], p[105];
int solve(int idx){
	if (idx == n){
		return 0;
	}
	int &ret = dp[idx],cost=10;
	if (ret != -1){
		return ret;
	}
	ret = 1e9;
	for (int i = idx; i < n; i++){
		cost += a[i];
		ret = min(ret, solve(i + 1) + cost * p[i]);
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
		clr(dp, -1);
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> p[i];
		}
		cout << solve(0) << endl;
	}
}