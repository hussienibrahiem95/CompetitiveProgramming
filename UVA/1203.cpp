#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
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
	set<pair<int,pair<int,int>>>s;
	string x;
	while (cin >> x&&x != "#"){
		int a, b;
		cin >> a >> b;
		s.insert({ b, { a, b } });
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++){
		cout << s.begin()->second.first << endl;
		auto te = s.begin();
		s.insert({ te->first + te->second.second, { te->second.first, te->second.second } });
		s.erase(*s.begin());
	}
}