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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	string x;
	cin >> x;
	stack<char>s;
	int ans = x.size();
	for (int i = 0; i < x.size(); i++){
		if (s.empty()||x[i]=='('){
			s.push(x[i]);
		}
		else if (s.top() == '('&&x[i] == ')'){
			s.pop();
		}
		else {
			s.push(x[i]);
		}
	}
	cout << ans - s.size() << endl;
}