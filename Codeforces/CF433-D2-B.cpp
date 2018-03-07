#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define __builtin_popcount __popcnt
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();

	int n;
	cin >> n;
	vector<ll>v1(n+1);
	for (int i = 1; i <= n; i++){
		cin >> v1[i];
	}
	vector<ll>v2 = v1,cum1(n+1),cum2(n+1);
	sort(all(v2));
	for (int i = 1; i <= n; i++){
		cum1[i] = cum1[i-1] + v1[i];
		cum2[i] = cum2[i - 1] + v2[i];
	}
	int q;
	cin >> q;
	while (q--){
		int l, r,t;
		cin >> t>>l >> r;
		if (t == 2)
			cout << cum2[r] - cum2[l - 1] << endl;
		else {
			cout << cum1[r] - cum1[l - 1] << endl;
		}
	}
}
