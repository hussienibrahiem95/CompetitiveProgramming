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
	string x;
	cin >> x;
	int k;
	cin >> k;
	ll sum = 0;
	ll mx = 0;
	ll a[30];
	for (int i = 0; i < 26; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < x.size(); i++){
		sum += (a[x[i] - 'a'] * (i+1));
	}
	ll idx = x.size();
	idx++;
	while (k--){
		sum += (idx++ * mx);
	}
	cout << sum << endl;
}