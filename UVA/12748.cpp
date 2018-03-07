#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define __builtin_popcount __popcnt
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
bool is_inCircle(int x1, int y1, int x2, int y2, int r){
	int x = (x1 - x2);
	int y = (y1 - y2);
	int dis = (x*x) + (y*y);
	return dis <= r*r;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t, nw = 1;
	cin >> t;
	while (t--){
		cout << "Case " << nw++ << ":\n";
		int n, y;
		cin >> n >> y;
		vector<pair<pair<int, int>, int>>v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].first.first >> v[i].first.second>>v[i].second;
		}
		for (int i = 0; i < y; i++){
			int x, y;
			cin >> x >> y;
			bool ok = 0;
			for (int j = 0; j < n; j++){
				if (is_inCircle(x, y, v[j].first.first, v[j].first.second, v[j].second)){
					ok = 1;
					break;
				}
			}
			if (ok){
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
}