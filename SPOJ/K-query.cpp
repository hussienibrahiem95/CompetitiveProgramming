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
const int N = 200001 + 20;
int a[N];
int bit[N], ans[N];
void add(int idx, int val){
	while (idx <= N){
		bit[idx - 1] += val;
		idx += (idx&-idx);
	}
}
int get(int idx){
	int sum = 0;
	while (idx > 0){
		sum += bit[idx - 1];
		idx -= (idx&-idx);
	}
	return sum;
}
/***You***Can***Do***It***/
int main()
{
	file();
	//fast();
	int n;
	scanf("%d", &n);
	map<int, set<int>>mp;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mp[a[i]].insert(i);
	}
	sort(a, a + n);
	reverse(a, a + n);
	int q;
	scanf("%d", &q);
	vector<pair<pair<int, int>, pair<int, int>>>v(q);
	int idx = 0;
	while (q--){
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		v[idx] = { { k, idx }, { x, y } };
		idx++;
	}
	sort(all(v));
	reverse(all(v));
	int pos = 0;
	for (int i = 0; i < v.size(); i++){
		while (pos < n&&a[pos]>v[i].first.first){
			add(*mp[a[pos]].begin() + 1, 1);
			mp[a[pos]].erase(mp[a[pos]].begin());
			pos++;
		}
		int x = v[i].second.first;
		int y = v[i].second.second;
		int sum = get(y) - get(x - 1);
		ans[v[i].first.second] = sum;
	}
	for (int i = 0; i < idx; i++){
		printf("%d\n", ans[i]);
	}
}