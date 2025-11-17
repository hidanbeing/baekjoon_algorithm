

class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        String[] words = {"aya", "ye", "woo", "ma"};
        
        for (String word : babbling){
            String temp = word;
            for (String str : words){
                temp = temp.replace(str, " ");
            }
            
            temp = temp.replace(" ", "");
            
            if (temp.length()==0){
                answer++;
            }
        }
        
        
        return answer;
    }
}