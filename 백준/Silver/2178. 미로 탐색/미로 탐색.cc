#include <iostream>
#include <queue>
using namespace std;

int miro[101][101];
int visited[101][101];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int res=0;

int n,m;



void bfs(int x, int y){
    if (x==n&&y==n) return;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        for (int i=0;i<4;i++){
            int newx=dx[i]+p.first;
            int newy=dy[i]+p.second;

            if (newx<0||newy<0) continue;

            if (visited[newx][newy]==0 && miro[newx][newy]==1){
                visited[newx][newy]=visited[p.first][p.second]+1;
                q.push(make_pair(newx,newy));
            }
        }
    }


}


int main(){
    cin>>n>>m;

    for (int i=0;i<n;i++){
        string str;
        cin>>str;
        for (int j=0;j<m;j++){
            miro[i][j] = str[j]-'0';
            visited[i][j]=0;
        }
    }

    visited[0][0]=1;
    bfs(0,0);

    /*
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<visited[n-1][m-1];

}