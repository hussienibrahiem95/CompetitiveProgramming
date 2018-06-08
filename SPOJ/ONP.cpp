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
	cin >> n;
	while (n--){
		string x;
		cin >> x;
		stack<char>s;
		for (int i = 0; i < x.size(); i++){
			if (x[i] == '(')
				continue;
			if (isalpha(x[i])){
				cout << x[i];
				continue;
			}
			if (x[i] == ')'){
				cout << s.top();
				s.pop();
				continue;
			}
			s.push(x[i]);
		}
		cout << endl;
	}
}