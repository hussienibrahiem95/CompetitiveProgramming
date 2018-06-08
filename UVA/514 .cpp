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
	while (cin >> n){
		if (!n){
			break;
		}
		int x;
		while (cin >> x&&x){
			vector<int>v(n);
			v[0] = x;
			for (int i = 1; i < n; i++){
				cin >> v[i];
			}
			int cur = 0;
			stack<int>s;
			for (int i = 1; i <= n; i++){
				s.push(i);
				while (!s.empty() && s.top() == v[cur]){
					s.pop();
					cur++;
				}
			}
			if (s.empty()){
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
		cout << "\n";
	}
}