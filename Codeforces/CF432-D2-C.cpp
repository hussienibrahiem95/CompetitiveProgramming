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
const int N = 100000 + 20;
bool prime[N];
void  sieve(){
	for (int i = 0; i < N; i++){
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for (int i = 2; i < N; i++){
		if (prime[i]){
			for (int j = i*2; j < N; j += i){
				prime[j] = 0;
			}
		}
	}
}

int pos[N];
int arr[N];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	sieve();
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		arr[i] = a;
		pos[a] = i;
	}

	vector<pair<int, int>>ans;
	for (int i = 1; i <= n; i++){
		int x = pos[i];
		while (pos[i] != i){
			int temp = i;
			while (!prime[pos[i] - temp + 1]){
				temp++;
			}
			ans.push_back({ temp, pos[i]});
			swap(arr[temp], arr[pos[i]]);
			swap(pos[arr[pos[i]]], pos[i]);
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}

}