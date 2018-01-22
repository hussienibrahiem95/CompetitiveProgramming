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
const int N = 200 + 20;
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n, m;
	cin >> n >> m;
	map<ll, ll>mp;
	int nw = 1;
	set<pair<ll,int>>s;
	for (int i = 0; i < n; i++){
		int c, t;
		cin >> c >> t;
		s.insert({ nw, i + 1 });
		s.insert({ nw + (c*t) - 1,i+1 });
		nw = nw + (c*t);
	}
	for (int i = 0; i < m; i++){
		int ti;
		cin >> ti;
		auto idx = s.lower_bound({ ti, -1 });
		if (idx != s.end()){
			cout << idx->second  << endl;
		}
	}
}