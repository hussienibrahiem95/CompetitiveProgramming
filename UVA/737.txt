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
	int n;
	while (cin >> n&&n){
		int x, y, z,d;
		cin >> x >> y >> z >> d;
		int mxx, mxy, mxz;
		int mnxd, mnyd, mnzd;
		mxx = x; mxy = y; mxz = z;
		mnxd = x + d; mnyd = y + d; mnzd = z + d;
		for (int i = 0; i < n-1; i++){
			cin >> x >> y >> z >> d;
			mxx = max(mxx, x);
			mxy = max(mxy, y);
			mxz = max(mxz, z);
			mnxd = min(mnxd, x+d);
			mnyd = min(mnyd, y+d);
			mnzd = min(mnzd, z + d);
		}
		ll a1 = mnxd-mxx;
		ll a2 = mnyd-mxy;
		ll a3 = mnzd-mxz;
		ll valume = a1 * a2 * a3;

		cout << max(valume, 0ll) << endl;
	}
}