#define _CRT_SECURE_NO_WARNINGS
#includebitsstdc++.h
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
void file(){
#ifndef ONLINE_JUDGE
	freopen(in.txt, r, stdin); freopen(out.txt, w, stdout);  
#endif
}
void fast(){
	stdios_basesync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
YouCanDoIt
int main()
{
	file();
	fast();
	string x;
	while (getline(cin,x)){
		string y;
		int cnt = 0;
		for (int i = 0; i  x.size(); i++){
			if (isalpha(x[i])){
				y += (x[i]);
			}
			else {
				if (y != ){
					y = ;
					cnt++;
				}
			}
		}
		if (y != ){
			cnt++;
		}
		cout  cnt  endl;
	}
}