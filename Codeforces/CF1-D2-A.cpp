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

ll n, m, a;
ll get_mn(){
	ll ans = 0;
	ans += ceil(n / (a* 1.0));
	m -= a;
	ans += (ans*ceil(m / (a*1.0)));
	return ans;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> m>>a;
	ll ans = 0;
	ans = get_mn();
	cout << ans << endl;
}