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
int dist(pair<int, int>a, pair<int, int>b){
	int x = abs(a.first - b.first);
	int y = abs(a.second - b.second);
	return x + y;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n){
		pair<int, int>nw(0, 0);
		int t = 0;
		vector < pair<int, int>>p(n);
		vector<int>t1(n);
		bool ok = 1;
		for (int i = 0; i < n; i++){
			cin >> t1[i] >> p[i].first >> p[i].second;
		}
		for (int i = 0; i < n; i++){
			int di = dist(nw, p[i]);
			if (nw == p[i]){
				ok = 0;
				break;
			}
			if ((di >(t1[i] - t)) || (di % 2 == 0 && di != (t1[i] - t))){
				ok = 0;
				break;
			}
			nw = p[i];
			t = t1[i];
		}
		if (ok)
			cout << "Yes" << endl;
		else {
			cout << "No" << endl;
		}
	}
}