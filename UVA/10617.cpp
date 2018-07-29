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
const int N = 100 + 20;
string x;
ll dp[N][N];
ll solve(int i, int j){
	if (i == j){
		return 1;
	}
	if (i > j){
		return 0;
	}
	ll &ret = dp[i][j];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	if (x[i] == x[j]){
		ret += solve(i + 1, j - 1) + 1;
	}
	ret += solve(i + 1, j);
	ret += solve(i, j - 1);
	ret -= solve(i + 1, j - 1);
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
		cin >> x;
		clr(dp, -1);
		cout << solve(0, x.size() - 1) << endl;
	}
}