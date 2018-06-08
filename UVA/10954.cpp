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
	while (cin >> n&&n){
		priority_queue<int, vector<int>, greater<int>>q;
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			q.push(a);
		}
		ll ans = 0;
		while (q.size()>=2){
			int f = q.top(); q.pop();
			int s = q.top(); q.pop();
			ans += (f + s);
			q.push(f+s);
		}
		cout << ans << endl;

	}
}