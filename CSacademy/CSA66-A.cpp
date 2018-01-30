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

	int n, m;
	cin >> n >> m;

	vector<int>v1(n), v2(m);
	for (int i = 0; i < n; i++){
		cin >> v1[i];
	}
	for (int i = 0; i < m; i++){
		cin >> v2[i];
	}
	int c1 = 0, c2 = 0;
	sort(all(v1));
	sort(all(v2));
	reverse(all(v2));
	int idx = 0;
	for (int i = n - 1; i >= 0; i--){
		if (idx == v2.size()){
			break;
		}
		if (v1[i] > v2[idx++]){
			c1++;
		}
		else {
			c2++;
		}
	}
	cout << c1 << " " << c2 << endl;
}