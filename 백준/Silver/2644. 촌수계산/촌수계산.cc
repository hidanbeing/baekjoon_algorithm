#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[101][101];
int visited[101];

int n;

void bfs(int x){
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int p=q.front();
        q.pop();
        for (int i=1;i<=n;i++){
            if (visited[i]==-1 && arr[p][i]==1){
                q.push(i);
                visited[i]=visited[p]+1;
            }
        }
    }

}

int main(){
	cin>>n;
	int a,b;
    cin>>a>>b;
    int m;
    cin>>m;
	for (int i=0;i<m;i++){
		int p,q;
        cin>>p>>q;
        arr[p][q]=1;
        arr[q][p]=1;
	}
    memset(visited, -1, sizeof(visited));
	visited[a]=0;
    bfs(a);
    cout<<visited[b];
}
