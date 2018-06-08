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
const int N = 50000 + 20;
struct node{
	ll prefixSum, suffixSum, Sum, maxSum;
};
node set_node(ll val){
	node cur;
	cur.maxSum = cur.Sum = cur.suffixSum = cur.prefixSum = val;
	return cur;
}
node merge(node left, node right){
	node cur;
	cur.Sum = left.Sum + right.Sum;
	cur.maxSum = max(max(left.maxSum, right.maxSum), (left.suffixSum + right.prefixSum));
	cur.prefixSum = max(left.prefixSum, left.Sum + right.prefixSum);
	cur.suffixSum = max(right.suffixSum, right.Sum + left.suffixSum);
	return cur;
}
node tree[4 * N];
ll a[N];
int n;
void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = set_node(a[l]);
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = merge(tree[left], tree[right]);
}
node solve(int cur, int l, int r, int x, int y){
	if (l > y || r < x){
		return set_node(-1e9);
	}
	if (l >= x&&r <= y){
		return tree[cur];
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	node le = solve(left, l, mid, x, y);
	node ri = solve(right, mid + 1, r,x, y);
	return merge(le, ri);
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
		cout << solve(1, 1, n, x, y).maxSum << endl;
	}
} 