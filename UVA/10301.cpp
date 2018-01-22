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
const double EPS = 1e-9;
const int N = 510 + 20;
typedef complex<double> point;
#define X real()
#define Y imag()
#define length(a)               (hypot((a).imag(), (a).real()))
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
// a^2 = b^2 + c^2 - 2*b*c*cos(A)
double getAngle_A_abc(double a, double b, double c){
	return acos(fixAngle( (b*b + c*c - a*a) / (2.0 * b*c)));
}
vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
	// Handle infinity case first: same center/radius and r > 0
	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return vector<point>(3, c1);    // infinity 2 same circles (not points)

	// Compute 2 intersection case and handle 0, 1, 2 cases
	double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

	if (::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
		ang2 = 0; // fix corruption

	vector<point> v(1, polar(r1, ang1 + ang2) + c1);

	// if point NOT on the 2 circles = no intersection
	if (dcmp(dp(v[0] - c1, v[0] - c1), r1*r1) != 0 ||
		dcmp(dp(v[0] - c2, v[0] - c2), r2*r2) != 0)
		return vector<point>();

	v.push_back(polar(r1, ang1 - ang2) + c1);
	if (same(v[0], v[1]))  // if same, then 1 intersection only
		v.pop_back();
	return v;
}
vector<int>parent, rank_v;
void intialize(int n){
	parent.resize(n + 1);
	rank_v.resize(n + 1);
	for (int i = 0; i <= n; i++){
		parent[i] = i;
		rank_v[i] = 1;
	}
}
int findpar(int x){
	if (x == parent[x]){
		return x;
	}
	return parent[x] = findpar(parent[x]);
}
void link(int x, int y){
	if (rank_v[x] > rank_v[y]){ // to put small into big tree
		swap(x, y);
	}
	parent[x] = y;
	if (rank_v[x] == rank_v[y]) {
		rank_v[y]++;
	}
}
bool union_sets(int x, int y){
	x = findpar(x);
	y = findpar(y);
	if (x != y){
		link(x, y);
	}
	return x != y;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int n;
	while (cin >> n&&n != -1){
		vector<pair<pair<double, double>, double>>circles(n);
		intialize(n + 1);
		for (int i = 0; i < n; i++){
			cin >> circles[i].first.first >> circles[i].first.second;
			cin >> circles[i].second; //  radius
		}
		int mx = 0;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				point a(circles[i].first.first, circles[i].first.second);
				point b(circles[j].first.first, circles[j].first.second);
				double r1 = circles[i].second;
				double r2 = circles[j].second;
				if (intersectCircleCircle(a, r1, b, r2).size()){
					union_sets(i, j);
				}
			}
		}
		map<int, int>mp;
		for (int i = 0; i < n; i++){
			mp[findpar(i)]++;
			mx = max(mx, mp[findpar(i)]);
		}
		if (mx == 1)
			cout << "The largest component contains " << mx << " ring.\n";
		else {
			cout << "The largest component contains " << mx << " rings.\n";
		}
	}
}