#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 2000000 + 20;
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
	int n;
	while (cin >> n&&n){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		merge_sort(0, n - 1);
		for (int i = 0; i < n-1; i++){
			cout << a[i] << " ";
		}
		cout << a[n - 1] << "\n";
	}

}