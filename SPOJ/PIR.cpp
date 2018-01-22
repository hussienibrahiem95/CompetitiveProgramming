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
const int N = 5;

// calculate Determinant of any matrix 
void getCofactor(double mat[N][N], double temp[N][N], double p, double q, double n)
{
	int i = 0, j = 0;
	// Looping for each element of the matrix
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those element
			//  which are not in given row and column
			if (row != p && col != q)
			{
				temp[i][j++] = mat[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
double determinantOfMatrix(double mat[N][N], int n)
{
	double D = 0; // Initialize result
	//  Base case : if matrix contains single element
	if (n == 1)
		return mat[0][0];
	double temp[N][N]; // To store cofactors
	int sign = 1;  // To store sign multiplier
	// Iterate for each element of first row
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of mat[0][f]
		getCofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
		// terms are to be added with alternate sign
		sign = -sign;
	}
	return D;
}
double mat[5][5];
/***You***Can***Do***It***/
int main()
{
	file();
	fast();
	int t;
	cin >> t;
	while (t--){
		double U, V, W, u, v, w;
		cin >> w >> v >> u >> U >> V >> W;
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++){
				if (i == j){
					mat[i][j] = 0;
				}
				else if (i == 4 || j == 4){
					mat[i][j] = 1;
				}
			}
		}
		mat[0][1] = u * u;
		mat[0][2] = v * v;
		mat[0][3] = w * w;
		mat[1][0] = u * u;
		mat[1][2] = W * W;
		mat[1][3] = V * V;
		mat[2][0] = v * v;
		mat[2][1] = W * W;
		mat[2][3] = U * U;
		mat[3][0] = w * w;
		mat[3][1] = V * V;
		mat[3][2] = U * U;
		double vv = determinantOfMatrix(mat, 5);
		cout << fixed << setprecision(4);
		cout << sqrt(vv / 288.0) << endl;
	}
}