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

	int t;
	cin >> t;
	while (t--){
		double U, V, W, u, v, w;
		cin >> w >> v >> u >> U >> V >> W;
		double X = (w - U + v) * (U + v + w);
		double x = (U - v + w) * (v - w + U);
		double Y = (u - V + w) * (V + w + u);
		double y = (V - w + u) * (w - u + V);
		double Z = (v - W + u) * (W + u + v);
		double z = (W - u + v) * (u - v + W);
		double a = sqrt(x * Y * Z);
		double b = sqrt(X * y * Z);
		double c = sqrt(X * Y * z);
		double d = sqrt(x * y * z);

		double v1 = -a + b + c + d;
		double v2 = a - b + c + d;
		double v3 = a + b - c + d;
		double v4 = a + b + c - d;
		v = sqrt(v1*v2*v3*v4) / (192.0 * (u *v*w));
		cout << fixed << setprecision(4);
		cout << v << endl;
	}
}