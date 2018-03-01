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
int a[103][103];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n){
		clr(a, 0);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		int mx = -1e9;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				a[i][j] += (a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]);
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				for (int ei = i; ei <= n; ei++){
					for (int ej = j; ej <= n; ej++){
						int s1 = a[i-1][j-1];
						int s2 = a[i - 1][ej];
						int s3 = a[ei][j - 1];
						int e = a[ei][ej];
						mx = max(e -  s2 - s3 + s1, mx);
					}
				}
			}
		}
		cout << mx << endl;
	}
	
}