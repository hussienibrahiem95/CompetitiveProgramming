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
	string org = "MARGARITA";
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		int cnt = 0;
		map<char, int>mp;
		for (int j = 0; j < x.size(); j++){
			mp[x[j]]++;
		}
		while (1){
			bool ok = 1;
			for (int j = 0; j < org.size(); j++){
				if (mp[org[j]]>=1){
					mp[org[j]]--;
				}
				else {
					ok = 0;
					break;
				}
			}
			if (ok)
				cnt++;
			else break;
		}
		cout << cnt << endl;
		
	}
}