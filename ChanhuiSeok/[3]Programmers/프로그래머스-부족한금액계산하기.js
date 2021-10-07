function solution(price, money, count) {
  var answer = -1;
  
  // count 횟수만큼 *2, *3, *4,...
  var required = 0;
  for (let i = 1; i<=count; i++){
      required = required + (price * i);
  }
  
  answer = required - money;
  
  if(answer <= 0) return 0;
  return answer;
}