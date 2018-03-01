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
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int l, r, k;
	cin >> l >> r >> k;
	l--;
	r++;
	int ans1 = l / k;
	int ans2 = r / k;
	cout << ans2 - ans1 << endl;
}