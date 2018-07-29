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
ll k;
int dp[101][101], n, mod = 1000000;
int solve(int idx, ll rem){
	if (idx ==1){
		return 1;
	}
	int &ret = dp[idx][rem];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	for (int i = 0; i <= rem; i++){
		ret = ret + (solve(idx - 1, rem - i) % (mod));
		ret %= mod;
	}
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	clr(dp, -1);
	while (cin >>n>> k){
		if (!n&&!k){
			return 0;
		}
		cout << solve(k, n) % mod << endl;
	}
}