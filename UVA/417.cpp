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
vector<string>all;
void solve(string a,char st){
	if (a.size() > 5){
		return;
	}
	if (a != ""){
		all.push_back(a);
	}
	for (char ch = st; ch <= 'z'; ch++){
		solve(a + ch,ch + 1);
	}
}
bool cmp(string a, string b){
	if (a.size() == b.size()){
		return a < b;
	}
	return a.size() < b.size();
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	solve("",'a');
	sort(all(all),cmp);
	string x;
	while (cin >> x){
		if (binary_search(all(all), x,cmp)){
			cout << lower_bound(all(all), x,cmp) - all.begin()  + 1<< endl;
		}
		else {
			cout << 0 << endl;
		}
	}

}