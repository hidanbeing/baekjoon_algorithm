class Solution {
    
    static int numLen;
    static int[] numbersArr; 
        
    int answer = 0;   
    
    public int solution(int[] numbers, int target) {
        numbersArr = numbers;
        numLen = numbers.length;
        
        int value=0;
        f(numbers[0], 0 , 0, target);
        f(numbers[0]*(-1), 0 , 0, target);
        
        return answer;
    }
    
    
    public int f(int cur, int value, int count, int target){
        int newValue = cur + value;
        count+=1;
        if (numLen == count){
            if (target == newValue){
                answer++;
            }
            return cur+value;
        }
        f(newValue, numbersArr[count] , count, target);
        f(newValue, numbersArr[count]*(-1) , count, target);

        return cur+value;

    }
}