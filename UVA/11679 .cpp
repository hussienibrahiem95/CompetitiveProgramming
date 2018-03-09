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
	int n, b;
	while (cin >> b >> n&&n != 0){
		vector<int>v(b + 1);
		for (int i = 1; i <= b; i++){
			cin >> v[i];
		}
		for (int i = 0; i < n; i++){
			int c, d, v1;
			cin >> c >> d >> v1;
			v[d] += v1;
			v[c] -= v1;
		}
		bool ok = 1;
		for (int i = 1; i <= b; i++){
			if (v[i] < 0){
				ok = 0;
			}
		}
		if (ok){
			cout << "S\n";
		}
		else {
			cout << "N\n";
		}
	}
}