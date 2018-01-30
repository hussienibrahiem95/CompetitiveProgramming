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
const int N = 1000 + 20;

int sz;
string arr[N];
bool vis[N][N];
bool valid(int i, int j){
	if (i < 0 || j < 0 || i >= sz){
		return 0;
	}
	if (j >= arr[i].size()){
		return 0;
	}
	if (vis[i][j])
		return 0;
	return 1;
}
void dfs(int i, int j){

	if (!valid(i,j))
		return;
	vis[i][j] = 1;
	arr[i][j] = '#';
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		string x;
		string last;
		sz = 0;
		clr(vis, 0);
		while (1){
			getline(cin, x);
			last = x;
			if (x[0] == '_')
				break;
			arr[sz++] = x;
		}
		for (int i = 0; i < sz; i++){
			for (int j = 0; j < arr[i].size(); j++){
				if (arr[i][j] != ' '&&arr[i][j]!='*'){
					vis[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < sz; i++){
			for (int j = 0; j < arr[i].size(); j++){
				if (arr[i][j] == '*'){
					dfs(i, j);
					i = sz;
					break;
				}
			}
		}
		for (int i = 0; i < sz; i++){
			cout << arr[i] << endl;
		}
		cout << last << endl;
	}
}