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
int a[103][103];

int max_sub_Array(int arr[], int n){
	int mx = -1e9;
	for (int i = 1; i <= n; i++){
		mx = max(mx, arr[i]);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += arr[i];
		if (sum < 0){
			sum = 0;
		}
		else {
			mx = max(sum, mx);
		}
	}

	return mx;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n){
		clr(a, 0);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		int mx = -1e9;
		for (int i = 1; i <= n; i++){
			int arr[101];
			clr(arr, 0);
			for (int j = i; j <= n; j++){
				for (int k = 1; k <= n; k++){
					arr[k] += a[k][j];
				}
				mx = max(mx, max_sub_Array(arr, n));
			}
		}
		cout << mx << endl;
	}
	
}