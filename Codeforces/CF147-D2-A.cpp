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
	string ans;
	while (cin >> x){
		ans += (x + " ");
	}
	string ans2;
	for (int i = 0; i < ans.size() - 1; i++){
		int sz = ans2.size();
		if (ans[i] == ' '&&sz!=0&&ans2[sz - 1] == ' ')
			continue;
		if (ans[i] != ' '&&!isalpha(ans[i])){
			if (ans2[sz-1] == ' '){
				ans2[sz-1] = ans[i];
				ans2 += ' ';
			}
			else {
				ans2 += ans[i];
				ans2 += ' ';
			}
		}
		else ans2 += ans[i];
		
	}
	cout << ans2 << endl;
}