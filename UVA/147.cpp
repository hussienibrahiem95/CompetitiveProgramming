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
const int N = 30001 + 20;
int a[] = { 5,10,20,50,100,200,500,1000,2000,5000,10000 };
ll dp[16][N], n;
ll solve(int idx, int sum){
	if (sum == 0){
		return 1;
	}
	if (idx == 11 || sum < 0){
		return 0;
	}
	ll &ret = dp[idx][sum];
	if (ret != -1){
		return ret;
	}
	ret = solve(idx + 1, sum);
	if (sum - a[idx]>=0)
		ret += solve(idx, sum - a[idx]);
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int doll, cent;
	char dot;
	clr(dp, -1);
	while (cin >> doll>>dot>>cent&& (doll || cent)){
		double x = doll +(cent / 100.0);
		cout << fixed << setprecision(2);
		cout << setw(6)<<x<< setw(17);
		cout << solve(0,doll * 100 + cent) << endl;
	}
}