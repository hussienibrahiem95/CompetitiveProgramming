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
const int N = 2000 + 20;
double dp[N][N];
int n, T;
double p;
bool vis[N][N];
double solve(int nw, int t){
	if (!nw){
		return n;
	}
	if (!t){
		return n - nw;
	}
	double &ret = dp[nw][t];
	if (vis[nw][t]){
		return ret;
	}
	ret = p*solve(nw - 1, t - 1);
	ret += (1 - p)*solve(nw, t - 1);
	vis[nw][t] = 1;
	return ret;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> p >> T;
	cout << fixed << setprecision(10);
	cout << solve(n, T) << endl;
}