// https://www.acmicpc.net/problem/2667
#include <bits/stdc++.h>
using namespace std;

int graph_[26][26];
int visited_[26][26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int n;
int r = 1;                 // 단지 ID 1부터
int p[626];                // ★ 최대 313개 대비 넉넉히(25*25=625)

// DFS: 현재 단지 r의 크기를 p[r]에 누적
void dfs(int x, int y){
    visited_[x][y] = 1;
    p[r] += 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        // ★ 상·하한 경계 모두 체크
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(!visited_[nx][ny] && graph_[nx][ny]==1){
            dfs(nx, ny);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++) graph_[i][j] = s[j]-'0';
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph_[i][j]==1 && !visited_[i][j]){
                dfs(i, j);
                r++;                 // 다음 단지 번호로
            }
        }
    }

    int comp = r - 1;               // 단지 수
    cout << comp << '\n';

    // ★ p[1]..p[comp]만 정렬 (끝은 배타적이므로 +1)
    sort(p+1, p+comp+1);

    for(int i=1;i<=comp;i++){
        cout << p[i] << '\n';
    }
    return 0;
}
