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
	while (cin >> n){
		if (n == 0){
			break;
		}
		cin.ignore();
		vector<int>v(n);
		for (int i = 0; i < n; i++){
			string x;
			getline(cin, x);
			int cnt=0;
			for (int j = 0; j < x.size(); j++){
				if (x[j] !='X'){
					cnt++;
				}
			}
			v[i] = cnt;
		}
		sort(all(v));
		int ans = 0;
		for (int i = 0; i < n; i++){
			ans += (v[i] - v[0]);
		}
		cout << ans << endl;
	}
}