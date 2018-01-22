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

#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;  // Parllel || identical

	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;

	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
	return true;
}

pair<double, point> findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b + a)*0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c)*0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair(length(a - center), center);
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	double x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		point a(x1, y1), b(x2, y2), c(x3, y3);
		cout <<fixed<<setprecision(2);
		cout << findCircle(a, b, c).first * 2 * 3.141592653589793 << endl;
	}
}