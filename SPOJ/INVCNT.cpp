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
const int N = 200000 + 20;
int a[N];
int temp[N];
ll inv_count;
void merge(int l, int r,int mid){
	int idx1=l, idx2=mid+1,cur=0;
	while (idx1<=mid&&idx2 <= r){
		if (a[idx1] <= a[idx2]){
			temp[cur++] = a[idx1++];
		}
		else {
			inv_count += (mid - idx1 + 1);
			temp[cur++] = a[idx2++];
		}
	}
	while (idx1<=mid){
		temp[cur++] = a[idx1++];
	}
	while (idx2<=r){
		temp[cur++] = a[idx2++];
	}
	cur = 0;
	for (int i = l; i <= r; i++){
		a[i] = temp[cur++];
	}
}

void merge_sort(int l,int r){
	if (r <= l){
		return;
	}
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, r,mid);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		inv_count = 0;
		merge_sort(0, n - 1);
		cout << inv_count << endl;
	}

}