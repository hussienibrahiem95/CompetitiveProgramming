#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
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
int flipBit(int num, int idx){
	return num ^ (1 << idx);
}

/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n){
		vector<int>w(1<<n),v(1 << n);
		for (int i = 0; i < (1 << n); i++){
			cin >> v[i];
		}
		for (int i = 0; i < (1 << n); i++){
			for (int j = 0; j < n; j++){
				w[i] += v[flipBit(i,j)];
			}
		}
		int mx = 0;
		for (int i = 0; i < (1 << n); i++){
			for (int j = 0; j < n; j++){
				mx = max(mx, w[flipBit(i, j)] + w[i]);
			}
		}
		cout << mx << endl;
	}
}