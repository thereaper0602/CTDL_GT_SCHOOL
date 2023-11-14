#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define M 1001

/*
10 11
1 2
1 5
1 10
1 3
2 4
3 6
3 7
3 9
6 7
5 8
8 9
*/

int n,m;
vector<int>adj[1001];
bool visited[1001];
void inp(){
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int x,y;cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
}

void

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main(){
	// inp();
	// bfs(10);
	int n = 0;
	if(n){
		cout << 'y' << endl;
	}
	else cout << 'n' << endl;
	return 0;
}