#include <iostream>
#include <vector>
#include<queue>
#include<cstring>
using namespace std;
#define M 1001
int a[M][M];
int v,e;
bool visited[1001];
int b[M][M];
// Given two vertices
/*
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
6 7
5 8
8 9
*/

void inp(){
	cin >> v >> e;
	for(int i = 1;i<=e;i++){
		int x,y;cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
}

void outp(){
	for(int i = 1;i<=v;i++){
		for(int j = 1;j<=v;j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void transform(){
	for(int i = 0;i<=v;i++){
		//cout << i << " : ";
		for(int j = 0;j<=v;j++){
			if(a[i][j] == 1 && i < j){
				b[i][j] = j;
				b[j][i] = i;
			}
		}
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	transform();
	while(!q.empty()){
		int w = q.front();
		q.pop();
		cout << w << " ";
		for(int i = 1;i <= v;i++){
			for(int j = 1;j <= v;j++){
				int x = b[i][j];
				if(x && !visited[x]){
					q.push(x);
					visited[x] = true;
				}
			}
		}
	}
}

int main() {
	inp();
	outp();
	bfs(1);
	//transform();
    return 0;
}
