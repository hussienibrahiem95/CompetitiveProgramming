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
	ll a, b;
	// one who have to choose multiple  is win 
	while (1){
		cin >> a >> b;
		if (a == 0 && b == 0){
			break;
		}
		int turn = 1;
		while (a != 0 && b != 0){
			if (b > a){
				swap(a, b);
			}
			ll f = a, i = 1;
			turn = 1 - turn;
			if (a / b > 1){
				break;
			}
			a -= (b*i);
		}
		if (turn == 0){
			cout << "Stan wins" << endl;
		}
		else {
			cout << "Ollie wins" << endl;
		}
	}
}