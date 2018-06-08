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
	string x;
	while (getline(cin,x)){
		string y;
		string ans;
		for (int i = 0; i < x.size(); i++){
			if (x[i]!=' '){
				y += (x[i]);
			}
			else {
				if (y != ""){
					reverse(all(y));
					ans += y + " ";
					y = "";
				}
			}
		}
		if (y != ""){
			reverse(all(y));
			ans += y;
		}
		cout << ans << endl;
	}
}