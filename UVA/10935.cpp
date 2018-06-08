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
	while (cin >> n){
		if (!n){
			break;
		}
		if (n == 1){
			cout << "Discarded cards:\n";
			cout << "Remaining card: 1\n";
			continue;
		}
		deque<int>dq;
		for (int i = 1; i <= n; i++){
			dq.push_back(i);
		}
		cout << "Discarded cards: ";
		while (dq.size() > 2){
			cout << dq.front() << ", ";
			dq.pop_front();
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front();
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
		cout << "\n";
		cout << "Remaining card: ";
		cout << dq.back() << "\n";
	}

}