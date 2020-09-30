class Solution {
	public static int answer=0;
    public int solution(int[] numbers, int target) {
    	findAll(numbers, target, 1, numbers[0]);
    	findAll(numbers, target, 1, numbers[0]*(-1));
        return answer;
    }
    public void findAll(int[] numbers, int target, int nowIndex, int sum) {
    	if(nowIndex==numbers.length) {
    		if(target==sum) {
    			answer++;
    		}
    		return;
    	}
    	findAll(numbers, target, nowIndex+1, sum+numbers[nowIndex]);
    	findAll(numbers, target, nowIndex+1, sum-numbers[nowIndex]);
    }
}
