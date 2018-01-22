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
bool can(ll x){

	ll m = sqrt(x);
	if (m*m == x){
		return 1;
	}
	return 0;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();

	int n;
	cin >> n;
	vector<int>v(n);
	map<int, int>mp;
	int mx = 0;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		mp[a]++;
		mx = max(mx, a);
	}
	int i = 1;
	for (i = 100000; i; i--){
		if (mp[i] % 2 != 0){
			break;
		}
	}
	if (i){
		cout << "Conan" << endl;
	}
	else {
		cout << "Agasa" << endl;
	}
}