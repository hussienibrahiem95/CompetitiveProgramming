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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n,k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int ans = 0, cnt = 0,skip=0;
	for (int i = 0; i < n; i++){
		if (k >= v[i]&&skip<=1){
			cnt++;
		}
		else {
			skip++;
		}
		ans = max(cnt, ans);
	}
	cout << ans << endl;
}