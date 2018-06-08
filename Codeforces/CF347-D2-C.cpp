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
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	cin >> n;
	int mx = 0;
	int gc = 1;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		mx = max(a, mx);
		if (!i)
			gc = a;
		gc = gcd(gc, a);
	}
	int new_n = mx / gc;
	if ((new_n - n) & 1){
		cout << "Alice\n";
	}
	else {
		cout << "Bob\n";
	}
}