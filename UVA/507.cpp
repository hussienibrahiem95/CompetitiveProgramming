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
	int t;
	cin >> t;
	int nw = 1;
	while (t--){
		ll mx_sum = -1,sti=0,enj=0,st_ti=0;
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n-1; i++){
			cin >> v[i];
		}
		ll sum = 0;
		for (int i = 0; i < n-1; i++){
			sum += v[i];
			if (sum < 0){
				sum = 0;
				st_ti = i+1;
			}
			else {
				if (sum>=mx_sum){
					if (sum == mx_sum&&i-st_ti<=enj-sti){
						continue;
					}
					mx_sum = sum;
					sti = st_ti;
					enj = i;
				}
			}
		}
		if (mx_sum == -1){
			cout << "Route " << nw++ << " has no nice parts\n";
		}
		else {
			cout << "The nicest part of route " << nw++ << " is between stops " << sti + 1;
			cout <<" and "<< enj + 2 << "\n";
		}

	}
}