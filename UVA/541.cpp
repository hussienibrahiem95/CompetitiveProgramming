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
int a[101][101];
int rows[101], cols[101];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n){
		if (!n)
			break;
		int chgr, chgc, r, c;
		r = c = chgc = chgr = 0;
		for (int i = 0; i < n; i++){
			int sumr = 0, sumc = 0;
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
				
			}
		}
		for (int i = 0; i < n; i++){
			int sumr=0, sumc = 0;
			for (int j = 0; j < n; j++){
				sumr += a[i][j];
				sumc += a[j][i];
			}
			if (sumr & 1){
				r++, chgr = i + 1;
			}
			if (sumc & 1){
				c++, chgc = i+1;
			}
		}
		
		if (!r&&!c){
			cout << "OK\n";
			continue;
		}
		if (r!=1||c!=1){
			cout << "Corrupt\n";
			continue;
		}
		cout << "Change bit (" << chgr << "," << chgc << ")\n";
		
	}
}