import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        boolean isTarget = false;
        for (String word : words){
            if (word.equals(target)) isTarget = true;
        }
        if (isTarget==false) return 0;
    
        int n = words.length;
        
        Queue<Node> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        
        for (int i=0;i<n;i++){
            if (check(words[i], begin)){
                q.offer(new Node(words[i], 1));
                visited[i]=true;
            }
        }
        
        while (!q.isEmpty()){
            Node node = q.poll();
            if (node.str.equals(target)){
                return node.depth;
            }
            for (int i=0;i<n;i++){
                if (!visited[i] && check(words[i], node.str)){
                    q.offer(new Node(words[i], node.depth+1));
                    visited[i]=true;    
                }
            }
        }
        int answer = 0;
        return answer;
    }
    
    
    
    public boolean check(String str1, String str2){
        int c = 0;
        for (int i=0;i< str1.length();i++){
            if (str1.charAt(i) != str2.charAt(i)) c++;
        }
        if (c == 1) return true;
        else return false;
    } 
    
    
    class Node{
        String str;
        int depth;
        Node(String s, int n){
            str = s;
            depth = n;
        }
    }
}