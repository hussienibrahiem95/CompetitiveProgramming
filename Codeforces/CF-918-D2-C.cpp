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
string x;
int solve(int i, int j){
	int op=0, clo=0, qu=0;
	int cnt = 0;
	for (int k = i; k <= j; k++){
		op += (x[k] == '(');
		if (x[k] == ')'){
			if (op){
				op--;
			}
			else if (qu){
				qu--;
			}
			else if (clo){
				clo--,op++;
			}
			else {
				k = j + 1;
			}
		}
		if (k<=j&&x[k] == '?'){
			if (op){
				op--,clo++;
			}
			else {
				qu++;
			}
		}
		if (k <= j){
			cnt += ((!op) && !(qu & 1));
		}
	}
	return cnt;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	while (cin >> x){
		int ans = 0;
		for (int i = 0; i < x.size(); i++){
			string m;
			ans += solve(i, (int)x.size() - 1);
		}
		cout << ans << endl;
	}
}