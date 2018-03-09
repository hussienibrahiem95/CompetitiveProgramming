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
const int N = 1000 + 20;
ll a[N][N];
ll anscol[1000001],ansrow[1000001];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	ll n, m, k, p;
	cin >> n >> m >> k >> p;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	priority_queue<ll>rows, cols;
	for (int i = 0; i < n; i++){
		ll sum = 0;
		for (int j = 0; j < m; j++){
			sum += a[i][j];
		}
		rows.push(sum);
	}
	for (int i = 0; i < m; i++){
		ll sum = 0;
		for (int j = 0; j < n; j++){
			sum += a[j][i];
		}
		cols.push(sum);
	}
	ll cur = 0;
	for (int i = 1; i <= k; i++){
		ll to = rows.top();
		cur += to;
		ansrow[i] = cur;
		rows.pop();
		rows.push(to - p*m);
	}
	cur = 0;
	for (int i = 1; i <= k; i++){
		ll to = cols.top();
		cur += to;
		anscol[i] = cur;
		cols.pop();
		cols.push(to - p*n);
	}
	ll ans = -1e18;
	for (ll i = 0; i <= k; i++){
		ans = max(ans, (ansrow[i] + anscol[k - i] - i*(k - i)*p));
	}
	cout << ans << endl;
}