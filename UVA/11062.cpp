#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
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
	set<string>s;
	string m;
	while (getline(cin,x)){
		if (x.empty())
			continue;
		for (int i = 0; i < x.size()-1; i++){
			if (isalpha(x[i]) || x[i] == '-'){
				m += tolower(x[i]);
			}
			else {
				if (m != ""){
					s.insert(m);
				}
				m = "";
			}
		}
		char last = x[x.size() - 1];
		if (isalpha(last)){
			m += last;
		}
		if (m != ""&&last!='-'){
			s.insert(m);
			m = "";
		}
	}
	for (auto it : s){
		cout << it << endl;
	}
}