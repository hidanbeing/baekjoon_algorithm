#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

/* 전역으로 처리 -> 0으로 초기화됨 */
int arr[1001][1001]; // 인접 행렬
int visited[1001]; // 방문 기록
// N: 정점의 개수, M: 간선의 개수, V: 탐색을 시작할 정점의 번호
int N, M, V; 

/* DFS 깊게 -> 재귀(스택) 후입선출 */
void DFS(int V) {
	visited[V] = 1;
	cout << V << " "; // 방문한 노드 출력 

	for (int i = 1; i <= N; i++) {
		if (arr[V][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
		if (i == N) {
			return;
		}
	}


}
/* BFS 넓게 -> 큐 선입선출*/
void BFS(int V) {
	queue<int> q;
	q.push(V);

	while (!q.empty()) {
		int next = q.front();
		visited[next] = 1;
		cout << next << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[next][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}

}

int main() {
	int u, v;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	DFS(V);

	cout << endl;
	memset(visited, 0, sizeof(visited));

	BFS(V);


}