#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
typedef unsigned long long ull;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
/***You***Can***Do***It***/
ull sum(ull a){
	return 	a*(a + 1) / 2;
}
int main()
{
	file();
	fast();
	ull a, b;
	int nw = 1;
	while (cin >> a >> b && a != 0){
		ull ans = 0;
		for (ull i = 1; i <= a; i++){
			ull cnt = a - i;
			ans += (cnt)* sum(b - 1);
		}
		cout << "Case " << nw++ << ": ";
		cout << ans << endl;	
	}
}