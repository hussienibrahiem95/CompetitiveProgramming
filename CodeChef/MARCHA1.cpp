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
int getbit1(int num, int idx){
	return ((1 << idx) & num) == (1 << idx);
	// return ((1 << idx) & num) != 0;
}
int getbit2(int num, int idx){
	return ((num>>idx) & 1) == 1;
}
int setbit0(int num, int idx){
	return num & ~(1 << idx);
}
int setbit1(int num, int idx){
	return num | (1 << idx);
}
int flipBit(int num, int idx){
	return num ^ (1 << idx);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	int a[100];
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		ll m;
		cin >> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		bool ok = 0;
		for (int i = 0; i < (1 << n); i++){
			ll sum = 0;
			for (int j = 0; j < n; j++){
				if (getbit1(i, j)){
					sum += a[j];
				}
			}
			if (sum == m){
				ok = 1;
				break;
			}
		}
		if (ok){
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
} 