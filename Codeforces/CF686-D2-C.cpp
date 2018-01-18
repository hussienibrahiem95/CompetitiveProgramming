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
int conv_string(string x){
	ll f = 1;
	ll num = 0;
	reverse(all(x));
	for (int i = 0; i < x.size(); i++){
		num += (f*(x[i] - '0'));
		f *= 7;
	}
	return num;
}
string conv_to7(int num){
	string x;
	while (num != 0){
		x += ('0' + (num % 7));
		num /= 7;
	}
	if (x.empty())
		x = "0";
	return x;
}
set<string>s1;
string x = "0123456";
int num_dig;
void gen(int i, string x1){
	if (x1.size() == num_dig){
		s1.insert(x1);
		return;
	}
	for (int j = i + 1; j < x.size(); j++){
		gen(j, x1 + x[j]);
	}
}
int main()
{
	file();
	fast();
	int n, m;
	cin >> n >> m;
	num_dig = conv_to7(n-1).size();
	gen(-1, "");
	set<string>s2;
	s2 = s1;
	s1.clear();
	num_dig = conv_to7(m-1).size();
	gen(-1, "");
	swap(s1, s2);
	set<string>f_s1,f_s2;
	for (auto it : s1){
		string prem = it;
		sort(all(prem));
		do{
			if (conv_string(prem)<n){
				f_s1.insert(prem);
			}
		} while (next_permutation(all(prem)));
	}
	
	for (auto it : s2){
		string prem = it;
		sort(all(prem));
		do{
			if (conv_string(prem) < m){
				f_s2.insert(prem);
			}
		} while (next_permutation(all(prem)));
	}
	set<string>ans;
	for (auto it1 : f_s1){
		for (auto it2 : f_s2){
			string y = it1 + it2;
			bool ok = 1;
			sort(all(y));
			for (int i = 0; i < y.size(); i++){
				if (y[i] == y[i + 1]){
					ok = 0;
					break;
				}
			}
			if (ok&&it1.size() &&it2.size()){
				ans.insert(it1+it2);
			}
		}
	}
	cout << ans.size() << endl;
}