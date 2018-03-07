#define _CRT_SECURE_NO_WARNINGS
#includebitsstdc++.h
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define __builtin_popcount __popcnt
void file(){
#ifndef ONLINE_JUDGE
	freopen(in.txt, r, stdin); freopen(out.txt, w, stdout);  
#endif
}
void fast(){
	stdios_basesync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
YouCanDoIt
int main()
{
	file();
	fast();
	int t;
	cin  t;
	while (t--){
		ll n, h;
		cin  n  h;
		vectorllv(n + 5),cum(n+5);
		for (int i = 1; i = n; i++){
			int l, r;
			cin  l  r;
			l++, r++;
			v[l]++;
			v[r+1]--;
		}
		for (int i = 1; i = n; i++){
			cum[i] = cum[i - 1] + v[i];
		}
		for (int i = 1; i = n; i++){
			cum[i] += cum[i - 1];
		}
		ll mx = 0;
		for (int i = h; i = n; i++){
			ll rem = cum[i] - cum[i-h];
			mx = max(mx,  rem);
		}
		cout  max(0ll,(nh) - mx)  endl;
	}
}
