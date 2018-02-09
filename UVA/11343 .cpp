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
const double EPS = 1e-9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
	// special case handling if a segment is just a point
	bool x = (p1 == p2), y = (p3 == p4);
	if (x && y)  return p1 == p3;
	if (x)   return ccw(p3, p4, p1) == 0;
	if (y)   return ccw(p1, p2, p3) == 0;

	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<pair<point,point>>lines;
		for (int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			point a(x, y);
			cin >> x >> y;
			point b(x, y);
			lines.push_back({ a, b });
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			bool ok = 1;
			for (int j = 0; j < n; j++){
				if (i == j)
					continue;
				if (intersect(lines[i].first, lines[i].second,
					lines[j].first, lines[j].second)){
					ok = 0;
					break;
				}
			}
			if (ok){
				ans++;
			}
		}
		cout << ans << endl;
	}
}