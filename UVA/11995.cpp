#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);  
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
		stack<int>st;
		queue<int>qu;
		priority_queue<int>pq;
		bool isst=1, isqu = 1, ispq = 1;
		for (int i = 0; i < n; i++){
			int x, v;
			cin >> x >> v;
			if (x==1){
				st.push(v);
				qu.push(v);
				pq.push(v);
			}
			else {
				if (!st.empty() && st.top() != v){
					isst = 0;
				}
				if (!qu.empty() && qu.front() != v){
					isqu = 0;
				}
				if (!pq.empty() && pq.top() != v){
					ispq = 0;
				}
				if (!st.empty()){
					st.pop();
				}
				else {
					isst = 0;
				}
				if (!qu.empty()){
					qu.pop();
				}
				else {
					isqu = 0;
				}
				if (!pq.empty()){
					pq.pop();
				}
				else {
					ispq = 0;
				}
			}
		}
		int ans = isqu + isst + ispq;
		if (!ans){
			cout << "impossible\n";
		}
		else if (ans > 1){
			cout << "not sure\n";
		}
		else {
			if (isqu){
				cout << "queue\n";
			}
			else if (isst){
				cout << "stack\n";
			}
			else {
				cout << "priority queue\n";
			}
		}
		
	}
}