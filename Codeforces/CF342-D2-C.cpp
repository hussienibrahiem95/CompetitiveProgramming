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
const int N = 510 + 20;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	ll r, h;
	cin >> r >> h;
	ll ans = (h / r) * 2;
	h = h%r;
	if (h >= 0.5 * r * sqrt(3)){
		ans += 3;
	}
	else if (h >= r / 2.0){
		ans += 2;
	}
	else {
		ans++;
	}
	cout << ans << endl;
}