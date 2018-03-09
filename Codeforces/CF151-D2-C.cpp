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
const int N = 1000 + 20;
bool isprime(ll n){
	if (n == 2){
		return 1;
	}
	if (n % 2 == 0){
		return 0;
	}
	for (ll j = 2; j*j <= n; j++){
		if (n%j == 0){
			return 0;
		}
	}
	return 1;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	ll p;
	cin >> p;
	if (isprime(p)){
		cout << 1 << "\n0\n";
		return 0;
	}
	vector<int>factors;
	for (ll j = 2; j*j <= p; j++){
		while (p%j == 0){
			factors.push_back(j);
			p /= j;
		}
	}
	if (p > 1){
		factors.push_back(p);
	}
	if (factors.size() == 2){
		cout << 2 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << factors[0] * factors[1] << endl;
}