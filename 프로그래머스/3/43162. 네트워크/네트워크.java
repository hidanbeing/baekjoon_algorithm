class Solution {
    boolean[] visited = new boolean[201];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        for (int i=0;i<n;i++){
            if (visited[i]==false){
                dfs(i,n,computers);
                answer++;
            }        
        }
        return answer;
    }
    
    // dfs 이용
    public void dfs(int v,int n, int[][] computers){
        visited[v] = true;
        
        for (int i=0;i<n;i++){
            if (visited[i]==true) continue;
            if (computers[v][i]==1){
                 dfs(i,n,computers);
            }
        }
    }
}