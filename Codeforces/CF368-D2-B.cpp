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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n,q;
	cin >> n;
	cin >> q;
	vector<int>v(n+1),cum(n+1);
	for (int i = 1; i <= n; i++){
		cin >> v[n-i + 1];
	}
	set<int>s;
	for (int i = 1; i <= n; i++){
		int sz = s.size();
		s.insert(v[i]);
		cum[i] = cum[i - 1] + (sz !=s.size());
	}
	reverse(all(cum));
	while (q--){
		int l;
		cin >> l;
		cout << cum[l-1] << endl;
	}
}
