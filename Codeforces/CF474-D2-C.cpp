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
typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b)                ((b)-(a))
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define length(a)               (hypot((a).imag(), (a).real()))
const double PI = acos(-1.0);
bool cmp(point a, point b){
	if (a.X == b.X)
		return a.Y < b.Y;
	return a.X < b.X;
}
bool cmp_doub(double a, double b){
	if (fabs(a - b) <= 1e-9){
		return 1;
	}
	return 0;
}
bool is_correct(point p1, point p2, point p3, point p4){
	vector<double>dists;
	double dist1 = length(p1 - p2);
	double dist2 = length(p2 - p4);
	double dist3 = length(p3 - p4);
	double dist4 = length(p3 - p1);
	double dist5 = length(p2 - p3);
	double dist6 = length(p1 - p4);
	dists.push_back(dist1);
	dists.push_back(dist2);
	dists.push_back(dist3);
	dists.push_back(dist4);
	dists.push_back(dist5);
	dists.push_back(dist6);
	sort(all(dists));
	if (cmp_doub(dists[0], dists[1]) && cmp_doub(dists[1], dists[2]) &&
		cmp_doub(dists[2], dists[3])
		&& cmp_doub(dists[3], dists[2])){
		if (cmp_doub(dists[4], dists[5]) && !cmp_doub(dists[5], dists[0])){
			return 1;
		}
	}
	return 0;
}
point rotate(point a, point b, int c){
	for (int i = 0; i < c; i++){
		a = rotateA(a, PI / 2.0, b);
	}
	return a;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		vector<pair<point, point>>points;
		for (int j = 0; j < 4; j++){
			int x, y, z, m;
			cin >> x >> y >> z >> m;
			points.push_back({ point(x, y), point(z, m) });
		}
		int ans = 1e9;
		for (int j1 = 0; j1 < 4; j1++){
			for (int j2 = 0; j2 < 4; j2++){
				for (int j3 = 0; j3 < 4; j3++){
					for (int j4 = 0; j4 < 4; j4++){
						vector<point> points1(4);
						points1[0] = rotate(points[0].first, points[0].second, j1);
						points1[1] = rotate(points[1].first, points[1].second, j2);
						points1[2] = rotate(points[2].first, points[2].second, j3);
						points1[3] = rotate(points[3].first, points[3].second, j4);
						if (is_correct(points1[0], points1[1], points1[2], points1[3])){
							ans = min(ans, j1 + j2 + j3 + j4);
						}
					}
				}
			}
		}
		if (ans == 1e9)
			ans = -1;
		cout << ans << endl;
	}
}