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
	cin >> n;
	vector<int>v1(n), v2(n),pos(n + 1);
	for (int i = 0; i < n; i++){
		cin >> v1[i];
	}
	for (int i = 0; i < n; i++){
		cin >> v2[i];
		pos[v2[i]] = i;
	}
	/*for (int i = 0; i < n; i++){
		cout << pos[v1[i]] << " ";
	}*/
	int until = 1;
	for (int i = 1; i < n; i++){
		if (pos[v1[i]] > pos[v1[i - 1]]){
			until++;
		}
		else {
			break;
		}
	}
	cout << n - until << endl;

}