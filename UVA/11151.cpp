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

string x;
int dp[1001][1001];
int solve(int i, int j){
	if (i > j){
		return 0;
	}
	if (i == j){
		return 1;
	}
	int &ret = dp[i][j];
	if (ret != -1){
		return ret;
	}
	if (x[i] == x[j]){
		ret = 2 + solve(i + 1, j - 1);
	}
	ret = max(ret, solve(i + 1, j));
	ret = max(ret, solve(i, j - 1));
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		clr(dp, -1);
		getline(cin, x);
		if (x.empty()){
			cout << 0 << endl;
		}
		else 
			cout << solve(0, (int)x.size() - 1) << endl;
	}
}