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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	for (int i = 0; i < n - 1; i++){
		if (v[i] < 0 || v[i]>v[i + 1]){
			cout << "NO" << endl;
			return 0;
		}
		if (v[i] == 0){
			continue;
		}
		v[i + 1] -= v[i];
	}
	if (v[n - 1] == 0){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}