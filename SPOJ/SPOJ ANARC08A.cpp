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
const int N = 4;
/***You***Can***Do***It***/
inline void rotatet_clockwise(vector<short>& a1){
	int a = a1[0], b=a1[1], c = a1[2], d = a1[3];
	a1[0] = c;
	a1[1] = a;
	a1[2] = d;
	a1[3] = b;
}
inline void rotatet_counterclockwise(vector<short> &a1){
	int a = a1[0], b = a1[1], c = a1[2], d = a1[3];
	a1[0] = b;
	a1[1] = d;
	a1[2] = a;
	a1[3] = c;
}
vector<short>mat(9);
short vis[9][9][9][9][9][9][9][9][9];

inline bool is_vis(vector<short>v){
	if (vis[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]][v[8]])
		return 1;
	return 0;
}
inline void set_val(vector<short>v, int val){
	vis[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]][v[8]] = val;
}
inline int  get_val(vector<short>v){
	return vis[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]][v[8]];
}
void inti(){
	for (int i = 0; i < 9; i++){
		mat[i] = i;
	}
}
void bfs(){
	vector<vector<short>>cho(4);
	cho[0] = { 0, 1, 3, 4 };
	cho[1] = { 1, 2, 4, 5 };
	cho[2] = { 3, 4, 6, 7 };
	cho[3] = { 4, 5, 7, 8 };
	queue<vector<short>> q;
	inti();
	q.push(mat);
	set_val(mat, 1);
	int dep = 1;
	while (!q.empty()){
		int sz = q.size();
		dep++;
		while (sz--){
			vector<short> node = q.front();
			q.pop();
			for (int i = 0; i < 4; i++){
				vector<short>temp(4), nxt;
				for (int j = 0; j < 4; j++){
					temp[j] = node[cho[i][j]];
				}
				rotatet_clockwise(temp);
				nxt = node;
				// update values in next node 
				for (int j = 0; j < 4; j++){
					nxt[cho[i][j]] = temp[j];
				}
				if (!is_vis(nxt)){
					q.push(nxt);
					set_val(nxt, dep);
				}
				for (int j = 0; j < 4; j++){
					temp[j] = node[cho[i][j]];
				}
				rotatet_counterclockwise(temp);
				nxt = node;
				// update values in next node 
				for (int j = 0; j < 4; j++){
					nxt[cho[i][j]] = temp[j];
				}
				if (is_vis(nxt) == 0){
					q.push(nxt);
					set_val(nxt, dep);
				}
			}
		}
	}
}
int main()
{
	file();
	fast();
	bfs();
	string x;
	int nw = 1;
	while (cin>>x){
		if (x == "0000000000"){
			break;
		}
		cout << nw++ << ". ";
		int cnt = x[0] - '0';
		vector<short>node(9);
		for (int i = 1; i < x.size(); i++){
			node[i - 1] = x[i] - '0';
			node[i - 1]--;
		}
		int ans = get_val(node);
		if (ans == 0||ans-1>cnt){
			cout << -1 << endl;
		}
		else {
			cout << ans-1 << endl;
		}
	}
}