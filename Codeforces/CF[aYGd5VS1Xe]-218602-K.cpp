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
const int N = 10000 + 20;
int n;
vector<int>v(N);
vector<int>ans_out;
int dp[N][3];
int solve(int i, int sign){
	int &ret = dp[i][sign];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	for (int j = i + 1; j < n; j++){
		if (sign == 1 && v[i]>v[j]){
			ret = max(ret,1+ solve(j, 0));
		}
		else if (sign == 0 && v[i] < v[j]){
			ret = max(ret,1+ solve(j, 1));
		}
	}
	return ret;
}
void build(int i, int sign){
	for (int j = i + 1; j < n; j++){
		if (sign == 1 && v[i]>v[j] && solve(j, 0) == dp[i][sign]-1){
			ans_out.push_back(j);
			build(j, 0);
			break;
		}
		else if (sign == 0 && v[i] < v[j] && solve(j, 1) == dp[i][sign] - 1){
			ans_out.push_back(j);
			build(j, 1);
			break;
		}
	}
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	clr(dp, -1);
	int ans1 = solve(0, 1);
	int ans2 = solve(0, 0);
	if (ans1>ans2){
		build(0, 1);
	}
	else {
		build(0, 0);
	}
	cout << ans_out.size()+1 << endl;
	cout << v[0] << " ";
	for (int i = 0; i < ans_out.size(); i++){
		cout << v[ans_out[i]] << " ";
	}
	cout << endl;
}