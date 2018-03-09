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
const int N = 200000 + 20;
ll mod = 1e9 + 7;
priority_queuell, vectorll, greaterllhigh;  dec
priority_queuelllow;  inc 
int sz = 0;
void upd(ll val){
	low.push(val);
	if (sz % 2 == 0){
		auto en = low.top();
		high.push(en);
		low.pop();
	}
	else {
		if (low.size() - 1 != high.size()){
			auto en = low.top();
			high.push(en);
			low.pop();
		}
		else {
			auto en = low.top();
			auto st = high.top();
			if (en  st){
				high.push(en);
				low.pop();
				low.push(st);
				high.pop();
			}
		}
	}
}
ll getmedian(){
	return low.top();
}
YouCanDoIt
int main()
{
	file();
	int t;
	cin  t;
	while (t--){
		ll a, b, c, n;
		scanf(%lld%lld%lld%lld, &a, &b, &c, &n);
		ll ans = 1;
		sz = 1;
		priority_queuelltemp;
		priority_queuell, vectorll, greaterllte1;  dec
		low = temp;
		high = te1;
		low.push(1);
		for (ll i = 2; i = n; i++){
			ll median = getmedian();
			ll val = (((a  median)) + ((bi)) + (c)) % mod;
			sz++;
			upd(val);
			ans += val;
		}
		printf(%lldn, ans);
	}
}