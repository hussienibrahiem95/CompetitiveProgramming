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
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, m;
char a[101][101], ch;
bool valid(int i, int j){
	if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '.')
		return 0;
	if (a[i][j] == ch)
		return 0;
	return 1;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n >> m >> ch;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	map<char, int>mp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == ch){
				for (int k = 0; k < 4; k++){
					int x = dx[k] + i;
					int y = dy[k] + j;
					if (valid(x, y)){
						mp[a[x][y]]++;
					}
				}
			}
		}
	}
	cout << mp.size() << endl;
}