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
const int N = 1000000 + 20;
int dp[N][3][3];
int n;
string s;
int solve(int i, int prev, int mod){
	if (i == n){
		if (prev == 1 && mod % 3 == 0){
			return 0;
		}
		return -1e9;
	}
	int &ret = dp[i][prev][mod];
	if (ret != -1){
		return ret;
	}
	ret = solve(i + 1, prev, mod);
	int num = s[i] - '0';
	if (num == 0){
		// 1 can , 2 can `t
		if (prev == 1){
			ret = max(ret, 1 + solve(i + 1, prev, mod));
		}
	}
	else {
		int nxtmod = (mod + (num % 3)) % 3;
		ret = max(ret, 1 + solve(i + 1, 1, nxtmod));
	}
	return ret;
}

void solve2(int i, int prev, int mod){
	if (i == n){
		return;
	}
	int ch1 = solve(i + 1, prev, mod);
	int ch2 = 0;
	int num = s[i] - '0';
	if (num == 0){
		// 1 can , 2 can `t
		if (prev == 1){
			ch2 = 1 + solve(i + 1, prev, mod);
		}
	}
	else {
		int nxtmod = (mod + (num % 3)) % 3;
		ch2 = 1 + solve(i + 1, 1, nxtmod);
	}

	int ans = solve(i, prev, mod);
	if (ch1 == ans){
		solve2(i + 1, prev, mod);
	}
	else {
		int nxtmod = (mod + (num % 3)) % 3;
		if (i<s.size())
			cout << s[i];
		solve2(i + 1, 1, nxtmod);
	}


}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();

	clr(dp, -1);
	cin >> s;
	n = (int)s.size();
	int ans = solve(0, 2, 0);
	if (ans <= 0){
		if (s.find("0") != string::npos){
			cout << 0 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}

	solve2(0, 2, 0);
	cout << endl;
}