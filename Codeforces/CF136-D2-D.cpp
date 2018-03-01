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

int dist(pair<int, int>a, pair<int, int>b){
	int x = a.first - b.first;
	int y = a.second - b.second;
	return (x*x + y*y);
}
bool is_rectangle(vector<pair<int, int>>p){
	vector<int>s;
	s.push_back(dist(p[0], p[1]));
	s.push_back(dist(p[1], p[2]));
	s.push_back(dist(p[2], p[3]));
	s.push_back(dist(p[3], p[0]));
	s.push_back(dist(p[0], p[2]));
	s.push_back(dist(p[1], p[3]));
	return s[0] == s[2] && s[1] == s[3] &&s[4]==s[5];
}
bool is_square(vector<pair<int, int>>p){
	set<int>s;
	for (int i = 0; i < 4; i++){
		for (int j = i+1; j < 4; j++){
			if (i == j)
				continue;
			s.insert(dist(p[i], p[j]));
		}
	}
	return s.size() == 2;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	vector<pair<pair<int, int>,int>>v(8);
	for (int i = 0; i < 8; i++){
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}
	sort(all(v));
	do{
		vector<pair<int, int>>v1,v2;
		v1 = { v[0].first, v[1].first, v[2].first, v[3].first };
		v2 = { v[4].first, v[5].first, v[6].first, v[7].first };
		if (is_rectangle(v1) && is_square(v2)){
			cout << "YES" << endl;
			
			for (int i = 4; i < 8; i++){
				cout << v[i].second + 1 << " ";
			}
			cout << endl;
			for (int i = 0; i < 4; i++){
				cout << v[i].second + 1 << " ";
			}
			cout << endl;
			return 0;
		}
	} while (next_permutation(all(v)));

	cout << "NO" << endl;
}