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
	ll n,k,p;
	cin >> n>>k>>p;
	bool ok = 0;
	if (n&1){
		k--;
		n--;
		ok = 1;
	}
	for (int i = 0; i < p; i++){
		ll x;
		cin >> x;
		if (x == n+1 && ok){
			if (k>=0)
				cout << "X";
			else cout << ".";
		}
		else {
			if (x % 2 == 0){
				if (k >= (n / 2)){
					cout << "X";
				}
				else {
					ll pos = x / 2;
					pos = n / 2 - pos + 1;
					if (pos <= k){
						cout << "X";
					}
					else {
						cout << ".";
					}
				}
			}
			else {
				if (k <= (n / 2)){
					cout << ".";
				}
				else {
					ll pos = x / 2 + 1;
					pos = n / 2 - pos + 1;
					ll rem = max(0ll,k- n/2);
					if (pos <= rem){
						cout << "X";
					}
					else {
						cout << ".";
					}
				}
			}
		}
	}
}