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
int a[101][101];
int rows[101], cols[101];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n){
		if (!n)
			break;
		bitset<32>a, b, s(n);
		bool flip=0;
		for (int i = 0; i < 32; i++){
			if (s[i] == 1){
				if (!flip){
					a[i] = 1;
				}
				else {
					b[i] = 1;
				}
				flip = !flip;
			}
		}
		cout << a.to_ullong() << " " << b.to_ullong() << endl;
	}
}