#define _CRT_SECURE_NO_DEPRECATE
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef    long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
void Run() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}
const int N = 200;
void print_v(vector<int>v) {
    for (int cur : v)
        cout << cur << " ";
    cout << endl;
}
string x, y;
int dp[N][N];
int solve(int i, int j) {
    if (i == x.size() && j == y.size())
        return 0;
    if (i == x.size())
        return (y.size() - j);
    if (j == y.size())
        return (x.size() - i);

    int &ret = dp[i][j];
    if (~ret)
        return ret;
    if (x[i] == y[j]) {
        return ret = solve(i + 1, j + 1);
    }
    
    ret = solve(i + 1, j) +1; // delete
    ret = min(ret, solve(i, j + 1) + 1); //insert
    ret = min(ret, solve(i + 1, j + 1) + 1); // replace
    return ret;
}

int cur;
int insert_cnt = 0;
void build(int i, int j) {
    if (i == x.size() && j == y.size())
        return;
    if (i == x.size()) {
        int sz = y.size() - j;
        for(int k=0;k<sz;k++) {
            cout << cur++ << " ";
            cout << "Insert " <<i+k+ 1 + insert_cnt <<","<< y[j] << endl;
            j++;
        }
        return;
    }
    if (j == y.size()) {
        while (i < x.size()) {
            cout << cur++ << " ";
            cout << "Delete " << i + 1 + insert_cnt<< endl;
            insert_cnt--;
            i++;
        }
        return;
    }

    if (x[i] == y[j]) {
        build(i + 1, j + 1);
        return;
    }
    int ch1 = solve(i + 1, j) + 1;
    int ch2 = solve(i, j + 1) + 1;
    int ch3 = solve(i + 1, j + 1) + 1;

    if (ch1 == dp[i][j]) {
        cout << cur++ << " ";
        cout << "Delete " << i + 1 + insert_cnt << endl;
        insert_cnt--;
        build(i + 1, j);
    }
    else if (ch2 == dp[i][j]) {
        cout << cur++ << " ";
        cout << "Insert " << i + 1 + insert_cnt <<","<<y[j] << endl;
        insert_cnt++;
        build(i, j + 1);
    }
    else {
        cout << cur++ << " ";
        cout << "Replace " << i + 1 + insert_cnt << "," << y[j] << endl;
        build(i + 1, j + 1);
    }
    
}
/***You***Can***Do***It***/
int main()
{

    Run();
    bool ok = 0;
    while (getline(cin,x) && getline(cin,y)) {
        clr(dp, -1);
        if (ok)
            cout << endl;
        cout << solve(0, 0) << endl;
        cur = 1;
        insert_cnt = 0;
        build(0, 0);
        ok = 1;
    }
}
