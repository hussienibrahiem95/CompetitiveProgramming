#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
int cum[N][N];

/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int h, w, n;
	while (cin >> h >> w >> n){
		if (h == w&&n == w&&n == 0){
			break;
		}
		clr(cum, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++){
			int sti, stj, eni, enj;
			cin >> sti >> stj >> eni >> enj;
			if (sti>eni){
				swap(sti, eni);
			}
			if (stj>enj){
				swap(stj, enj);
			}
			cum[sti][stj]++;
			cum[eni + 1][stj]--;
			cum[sti][enj + 1]--;
			cum[eni + 1][enj + 1]++;
		}
		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				cum[i][j] += cum[i - 1][j];
			}
		}
		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				cum[i][j] += cum[i][j-1];
			}
		}
		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				cnt += cum[i][j] == 0;			
			}
		}
		int ans =  cnt;
		if (ans == 0){
			cout << "There is no empty spots.\n";
		}
		else if (ans == 1){
			cout << "There is one empty spot.\n";
		}
		else {
			cout << "There are "<<ans;
			cout << " empty spots.\n";
		}
	}
}