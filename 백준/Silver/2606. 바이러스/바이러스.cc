// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int graph[101][101];
int visited[101];
int r=0;

void dfs(int x, int n){
    visited[x]=1;
    for (int i=1;i<=n;i++){
        if (visited[i]==0&&graph[x][i]==1){
            dfs(i,n);
    r++;

        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    dfs(1,n); 

    cout<<r;
}