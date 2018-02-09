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
const int N = 200000 + 20;
ll n, k;
ll a[N];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> k;
	map<ll, ll>mp1,mp2;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mp1[a[i]]++;
	}
	ll ans = 0;
	reverse(a,a+n);
	for (int i = 0; i < n; i++){
		mp1[a[i]]--;
		if (a[i] % k == 0){
			ll f = mp1[a[i] / k]; 
			ll s = mp2[a[i] * k];
			ans += (f*s);
		}
		mp2[a[i]]++;
	}
	cout << ans << endl;
}