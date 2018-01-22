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
int n,m;
string a[N];
int answ[N];
bool check(string x){
	for (int i = 1; i < m; i++){
		int c = 0;
		for (int j = 0; j < n; j++){
			if (x[j] == a[i][j]){
				c++;
			}
		}
		if (c != answ[i]){
			return 0;
		}
	}
	return 1;
}
set<string>s;
map<string, int>mp;
void gen(int st,string x,int c){
	if (c < 0)
		return;
	if (c == 0){
		s.insert(x);
	}
	for (int i = st+1; i < x.size(); i++){
		string temp = x;
		temp[i] = (1 - (temp[i] - '0')) + '0';
		gen(i, temp, c - 1);
	}
}
int main()
{
	file();
	fast();
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> answ[i];
	}
	for (int i = 0; i < a[0].size(); i++){
		a[0][i] = (1 - (a[0][i]-'0')) + '0';
	}
	int ans = 0;
	gen(-1, a[0], answ[0]);
	for (auto it : s){
		if (check(it)){
			ans++;
		}
	}
	cout << ans << endl;
}