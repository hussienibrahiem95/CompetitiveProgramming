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
	int t;
	cin >> t;
	while (t--){
		string x, y;
		cin >> x >> y;
		map<string, string>mp1, mp2;
		string key, val;
		bool who = 0;
		for (int i = 1; i < x.size(); i++){
			if (x[i] == ':'){
				who = 1;
				continue;
			}
			if (x[i] == ',' || x[i] == '}'){
				if (key != "" && val != ""){
					mp1[key] = val;
					key = val = "";
					who = 0;
				}
				continue;
			}
			if (!who){
				key += x[i];
			}
			else {
				val += x[i];
			}
		}
		key = val = "";
		who = 0;
		swap(x, y);
		for (int i = 1; i < x.size(); i++){
			if (x[i] == ':'){
				who = 1;
				continue;
			}
			if (x[i] == ',' || x[i] == '}'){
				if (key != "" && val != ""){
					mp2[key] = val;
					key = val = "";
					who = 0;
				}
				continue;
			}
			if (!who){
				key += x[i];
			}
			else {
				val += x[i];
			}
		}
		vector<string>v1, v2, v3; // + , - ,*
		for (auto it : mp2){
			if (mp1.find(it.first) == mp1.end()){
				v1.push_back(it.first);
			}
			else if(mp1[it.first] !=it.second){
				v3.push_back(it.first);
			}
		}
		for (auto it : mp1){
			if (mp2.find(it.first) == mp2.end()){
				v2.push_back(it.first);
			}
		}
		if (v1.size()){
			cout << "+";
			sort(all(v1));
			for (int i = 0; i < (int)v1.size() - 1; i++){
				cout << v1[i]<<",";
			}
			cout << v1[v1.size() - 1]<<"\n";
		}
		if (v2.size()){
			cout << "-";
			sort(all(v2));
			for (int i = 0; i < (int)v2.size() - 1; i++){
				cout << v2[i] << ",";
			}
			cout << v2[v2.size() - 1]<<"\n";
		}
		if (v3.size()){
			cout << "*";
			sort(all(v3));
			for (int i = 0; i < (int)v3.size() - 1; i++){
				cout << v3[i] << ",";
			}
			cout << v3[v3.size() - 1]<<"\n";
		}
		if (!v1.size() && !v2.size() && !v3.size()){
			cout << "No changes\n";
		}
		cout << endl;
	}
}