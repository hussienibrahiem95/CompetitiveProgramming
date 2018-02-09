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
struct data{
	string x;
	int a, b;
};
vector<data>v(20);
int n;
bool check(vector<int>s){

	for (int i = 0; i < n; i++){
		int a1=0, b1 = 0;
		int idx = 0;
		for (auto it : s){
			int num = v[i].x[idx] - '0';
			if (it == num){
				a1++;
			}
			else if (find(all(s),num) != s.end()){
				b1++;
			}
			idx++;
		}
		
		if (a1 != v[i].a || b1 != v[i].b){
			return 0;
		}
	}
	return 1;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].a >> v[i].b;
	}
	set<vector<int>>ans;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 10; k++){
				for (int z = 0; z < 10; z++){
					set<int>s;
					s = { i, j, k, z };
					if (s.size() < 4){
						continue;
					}
					vector<int>v;
					v = { i, j, k, z };
					if (check(v)){
						ans.insert(v);
					}
				}
			}
		}
	}
	if (ans.size() == 1){
		for (auto it : *ans.begin()){
			cout << it;
		}
	}
	else if (ans.size() == 0){
		cout << "Incorrect data" << endl;
	}
	else {
		cout << "Need more data" << endl;
	}
}