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
	int t;
	cin >> t;
	int nw = 1;
	while (t--){
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << "Case " << nw++ << ": ";
		cout << a[1] << "\n";
	}
}