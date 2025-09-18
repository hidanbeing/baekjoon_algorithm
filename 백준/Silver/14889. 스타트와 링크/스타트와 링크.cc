#include <iostream>
#include <algorithm>

using namespace std;

int n;
int S[21][21];
bool visited[21];

int best=1e9;

int diff() {
    int teamA = 0, teamB = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {   // i<j만
            int w = S[i][j] + S[j][i];
            if (visited[i] && visited[j])      teamA += w;   // 둘 다 A팀
            else if (!visited[i] && !visited[j]) teamB += w; // 둘 다 B팀
        }
    }
    return abs(teamA - teamB);
}


void dfs(int picked, int start){
    if (picked==n/2){
        best = min(best, diff());
        return;
    }

    int remain = n-start;
    int need = n/2-picked;

    for (int i=start;i<n;i++){
        if (visited[i]==true) continue;
        visited[i] = true;
        dfs(picked+1, i+1);
        visited[i]=false;
    }

}

int main(){
    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>S[i][j];
        }
    }

    visited[0] = true;

    dfs(1,1);

    cout<<best;
}