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
bool can(int x){
	if (x % 10 == 7){
		return 1;
	}
	x /= 10;
	if (x == 7){
		return 1;
	}
	return 0;
}
int main()
{
	file();
	fast();

	int x, y, z;
	cin >> x >> y >> z;
	int ned = 0;

	while (1){
		if (can(y) || can(z)){
			cout << ned << endl;
			return 0;
		}
		ned++;
		for (int j = 0; j < x; j++){
			z--;
			if (z == -1){
				z = 59;
				y--;
			}
			if (y == -1){
				y = 23;
			}
		}
	}

}