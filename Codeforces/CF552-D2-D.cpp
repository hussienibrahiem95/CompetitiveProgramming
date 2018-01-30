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
bool istriangle(pair<int, int>a, pair<int, int>b, pair<int, int>c){
	int x = a.first *(b.second - c.second);
	int y = b.first *(c.second - a.second);
	int z = c.first *(a.second - b.second);

	if ((x + y + z) != 0)
		return 1;
	return 0;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	cin >> n;
	vector<pair<int, int>>points;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			for (int k = j + 1; k < n; k++){
				if (istriangle(points[i], points[j], points[k])){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}