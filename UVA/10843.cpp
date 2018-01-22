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
const int N = 200 + 20;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	int nw = 1;
	while (t--){
		ll n;
		cin >> n;
		ll mod = 2000000011;
		cout << "Case #" << nw++ << ": ";
		if (n == 1 || n == 2){
			cout << "1" << endl;
		}
		else {
			ll ans = n;
			for (int i = 0; i < n - 3; i++){
				ans *= n;
				ans %= mod;
			}
			cout << ans << endl;
		}
	}
}
