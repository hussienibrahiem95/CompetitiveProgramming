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
	while (cin >> x){
		deque<string>ans;
		string y;
		bool back = 1;
		for (int i = 0; i < x.size(); i++){
			if (x[i] == '['){
				if (back){
					ans.push_back(y);
				}
				else {
					ans.push_front(y);
				}
				y.clear();
				back = 0;
				continue;
			}
			if (x[i] == ']'){
				if (back){
					ans.push_back(y);
				}
				else {
					ans.push_front(y);
				}
				y.clear();
				back = 1;
				continue;
			}
			y += x[i];
		}
		if (y!=""){
			if (back){
				ans.push_back(y);
			}
			else {
				ans.push_front(y);
			}
		}
		while (!ans.empty()){
			cout << ans.front();
			ans.pop_front();
		}
		cout << endl;
	}
}