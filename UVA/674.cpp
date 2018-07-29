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
const int N = 7489 + 20;
int a[] = { 1, 5, 10, 25, 50 };
int dp[10][N], n;
ll solve(int idx, int sum){
	if (sum <0){
		return 0;
	}
	if (idx == 5){
		return sum == 0;
	}
	int &ret = dp[idx][sum];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	ret += solve(idx + 1, sum);
	ret += solve(idx, sum - a[idx]);
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	clr(dp, -1);
	while (cin >> n){
		cout << solve(0, n) << endl;
	}
}