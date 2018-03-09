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
	cin >> n;
	int vis[N];
	clr(vis, 0);
	for (int i = 0; i < n; i++){
		int mx = 0;
		for (int j = 0; j < n; j++){
			int a;
			cin >> a;
			mx = max(mx, a);
		}
		if (vis[mx]){
			for (int j = mx + 1; j <= n; j++){
				if (!vis[j]){
					cout << j << " ";
					vis[j] = 1;
					break;
				}
			}
		}
		else {
			cout << mx << " ";
			vis[mx] = 1;
		}
	}
}