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
const int N = 100000 + 20;
int n;
ll cum[N];
ll get_ans(ll k){
	ll pw = 1;
	ll ans = 0;
	ll k1 = k;
	for (int i = n - 1; i;){
		ll l = max(0ll, i - k);
		ll r = i;
		ll sum = cum[r] - cum[l];
		ans += (sum* pw);
		pw++;
		k *= k1;
		i = l;
	}
	return ans;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	vector<ll>v(n+1);
	map<int, ll>vis;
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	sort(all(v));
	cum[0] = 0;
	for (int i = 1; i<=n; i++){
		cum[i] = cum[i - 1] + v[i];
	}
	int q;
	cin >> q;
	while (q--){
		int k;
		cin >> k;
		if (vis[k]){
			cout << vis[k] << endl;
		}
		else {
			vis[k] = get_ans(k);
			cout << vis[k] << " ";
		}
	}
}