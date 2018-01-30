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

	vector<int>f(50);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < 30; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		if (binary_search(all(f), i)){
			cout << "O";
		}
		else cout << "o";
	}
	cout << endl;

}