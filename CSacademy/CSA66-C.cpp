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
const int N = 1000000 + 20;
int divs[N];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	ll t;
	cin >> n>>t;
	map<int, int>cnt;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		cnt[a]++;
	}
	for (auto it : cnt){
		int num = it.first;
		int c = it.second;
		for (int j = num; j <= t; j += num){
			divs[j] += c;
		}
	}
	int mx = 0;
	for (int i = 1; i <= t; i++){
		mx = max(divs[i], mx);
	}
	cout << mx << " ";
	int c = 0;
	for (int i = 1; i <= t; i++){
		if (divs[i] == mx){
			c++;
		}
	}
	cout << c << endl;
	
}