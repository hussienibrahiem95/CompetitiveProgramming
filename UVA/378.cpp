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
#define X real()
#define Y imag()
typedef complex<double> point;
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
const int N = 4;
double fix(double x){
	stringstream xx;
	xx << x;
	string y;
	xx >> y;
	if (y[0] == '-'&&y[1] == '0'&&y.size()==2){
		return 0;
	}
	return x;
}
point get_point_intersection(point a,point b,point c,point d){
	// a1x + b1y = c1  , a1= ( y1 - y2 ) , b1 (x1 - x2) , 
	// c1 = a1 * x1 + b1 * y1 or c1 = a1 * x2 + b1 * y2
	double a1 = b.Y - a.Y;
	double b1 = a.X - b.X;
	double c1 = a1*(a.X) + b1*(a.Y);

	// Line cd represented as a2x + b2y = c2
	double a2 = d.Y - c.Y;
	double b2 = c.X - d.X;
	double c2 = a2*(c.X) + b2*(c.Y);

	double determinant = a1*b2 - a2*b1; // lines parallel if determinant 0 
	if (determinant == 0){
		return point(-1e9, -1e9);
	}
	double x = (b2*c1 - b1*c2) / determinant;
	double y = (a1*c2 - a2*c1) / determinant;
	return point(fix(x), fix(y));
}
bool isCollinear(point a, point b, point c) {
	return fabs(cp(b - a, c - a)) < EPS;
}
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT\n";
	while (t--){
		double x1, x2, x3, x4, y1, y2, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		point a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
		if (isCollinear(a, b, c) && isCollinear(b, c, d)){
			cout << "LINE" << endl;
		}
		else {
			point ans = get_point_intersection(a, b, c, d);
			if (ans.X == -1e9){
				cout << "NONE" << endl;
			}
			else {
				point ans = get_point_intersection(a, b, c, d);
				cout << fixed << setprecision(2);
				cout << "POINT ";
				cout << ans.X << " " << ans.Y << endl;
			}
		}
	}
	cout << "END OF OUTPUT\n";
}