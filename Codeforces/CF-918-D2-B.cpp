﻿#define _CRT_SECURE_NO_WARNINGS
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
	int n, m;
	cin >> n >> m;
	map<string, string>mp;
	for (int i = 0; i < n; i++){
		string x, y;
		cin >> x >> y;
		mp[y] = x;
	}

	for (int i = 0; i < m; i++){
		string x, y;
		cin >> x >> y;
		y.pop_back();
		cout << x << " " << y << "; #" << mp[y] << endl;
	}

}