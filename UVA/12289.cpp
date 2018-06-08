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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		if (x.size()>3){
			cout << 3 << endl;
			continue;
		}
		string one = "one";
		int c = 0;
		for (int i = 0; i < x.size(); i++){
			if (x[i] != one[i]){
				c++;
			}
		}
		if (c<=1){
			cout << 1 << endl;
			continue;
		}
		cout << 2 << endl;
	}
}