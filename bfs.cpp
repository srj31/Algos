#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;


vector<vector<int> > adj(MAX_N);
int n;

vector<int> d;
vector<int> p;
vector<bool> v;

void bfs(int root){
	v[root] = true;
	p[root] = -1;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int start = q.front();
		cout << start << " ";
		q.pop();
		// v[start] = true;
		for(auto child:adj[start]){
			if(!v[child]){
				d[child] = d[start]+ 1;
				v[child] = true;
				p[child]=start;
				q.push(child);
			}
		}
	}
}

int main(){
	cin >> n;
	d.assign(n,0);
	p.assign(n,0);
	v.assign(n,false);
	int m;
	// cout << ""
	cin >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// cout << "done" << endl;
	bfs(0);


}