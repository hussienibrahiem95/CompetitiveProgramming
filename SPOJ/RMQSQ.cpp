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
const int N = 1e5 + 20;
int tree[4 * N];
int a[N];
int n;
void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = a[l];
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = min(tree[left], tree[right]);
}
int solve(int cur, int l, int r, int x, int y){
	if (l > y || r < x){
		return INT_MAX;
	}
	if (l >= x&&r <= y){
		return tree[cur];
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	int cho1 = solve(left, l, mid, x, y);
	int cho2 = solve(right, mid + 1, r, x, y);
	return min(cho1, cho2);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--){
		int x, y;
		cin >> x >> y;
		x++, y++;
		if (x > y){
			swap(x, y);
		}
		cout << solve(1, 1, n, x, y) << endl;
	}
}