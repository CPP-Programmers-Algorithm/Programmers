function solution(n, t, m, p) {
  var answer = "";
  let num = 0;
  let str = "";
  while (num < t * m) {
    str += num.toString(n).toUpperCase();
    num++;
  }

  let idx = p - 1;
  while (answer.length < t) {
    answer += str[idx];
    idx += m;
  }

  return answer;
}
