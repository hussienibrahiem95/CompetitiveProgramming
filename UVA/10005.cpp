#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define __builtin_popcount __popcnt
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 510 + 20;
int n;
vector<pair<double, double>>v(N);
double r;
double dist(double x1, double y1, double x2, double y2){
	double x = (x1 - x2);
	double y = (y1 - y2);
	double dis = (x*x) + (y*y);
	return dis;
}
pair<double,double> center(double x1, double y1, double x2, double y2, double rr) {
	double ab = dist(x1,y1,x2,y2);
	double k = sqrt(rr / ab - 0.25);
	pair<double, double> o;
	o.first = (x1 + x2) / 2.0 + k * (y2 - y1);
	o.second = (y1 + y2) / 2.0 + k * (x1 -x2);
	return o;
}
bool is_inCircle(double x1, double y1, double x2, double y2, double r){
	double x = (x1 - x2);
	double y = (y1 - y2);
	double dis = (x*x) + (y*y);
	return dis <= r;
}
int count_num(double x, double y){
	int c = 0;
	for (int j = 0; j < n; j++){
		if (is_inCircle(x, y,v[j].first,v[j].second,r)){
			c++;
		}
	}
	return c;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	while (1){
		cin >> n;
		if (!n)
			break;
		for (int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
		}
		cin >> r;
		r *= r;
		int mx = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j){
					continue;
				}
				pair<double,double> cen = center(v[i].first,v[i].second,v[j].first,v[j].second,r);
				mx = max(mx, count_num(cen.first, cen.second));
			}
		}
		if (mx == n || n == 1){
			cout << "The polygon can be packed in the circle.\n";
		}
		else {
			cout << "There is no way of packing that polygon.\n";
		}
	}
}