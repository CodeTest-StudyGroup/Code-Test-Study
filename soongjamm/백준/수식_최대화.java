import java.util.ArrayList;
import java.util.Arrays;

class Solution {

    ArrayList<ArrayList<String>> permutedOps = new ArrayList<>();
    ArrayList<String> operations = new ArrayList<>();
    long answer = 0l;

    public long solution(String expression) {
        // 우선 수식만 꺼낸다.
        // 꺼낸 수식으로 DFS를 이용해 순열을 만든다.
        operations = getOperations(expression);
        permutate(new boolean[operations.size()], 0, new String[operations.size()]);

        // 모든 우선순위 순열에 대해 주어진 수식을 계산해본다.
        // 주어진 계산식을 숫자, 기호로 분리한 리스트가 필요하다.
        ArrayList<String> tokenizedExpression = tokenize(expression);
        for (ArrayList<String> ops : permutedOps) {
            long result = 0l;
            ArrayList<String> exp = new ArrayList<>(tokenizedExpression);
            for (String op : ops) {
                int idx = 0;
                while (idx < exp.size()) {
                    if (op.equals(exp.get(idx))) {
                        long a = Long.parseLong(exp.get(idx - 1));
                        long b = Long.parseLong(exp.get(idx + 1));
                        long value = calculate(a, op, b);
                        exp.set(idx, Long.toString(value));
                        exp.remove(idx + 1);
                        exp.remove(idx - 1);
                        continue;
                    }
                    idx++;
                }
            }
            result = Long.parseLong(exp.get(0));
            answer = Math.max(answer, Math.abs(result));
        }

        return answer;
    }

    private long calculate(long a, String op, long b) {
        long result = 0l;
        switch (op) {
            case "+":
                result = a + b;
                break;
            case "-":
                result = a - b;
                break;
            case "*":
                result = a * b;
                break;
        }

        return result;
    }

    private ArrayList<String> tokenize(String expression) {
        ArrayList<String> exp = new ArrayList<>();
        String tmp = "";
        for (char c : expression.toCharArray()) {
            if (c == '+' || c == '-' || c == '*') {
                exp.add(tmp);
                exp.add(Character.toString(c));
                tmp = "";
                continue;
            }
            // 숫자일 때
            tmp += c;
        }
        // 마지막에 오는 숫자도 추가해줘야 한다.
        exp.add(tmp);
        return exp;
    }

    private void permutate(boolean[] visited, int depth, String[] output) {
        if (depth == operations.size()) {
            ArrayList<String> newPermutation = new ArrayList<>(Arrays.asList(output));
            permutedOps.add(newPermutation);
            return;
        }
        for (int i = 0; i < operations.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                output[depth] = operations.get(i);
                permutate(visited, depth + 1, output);
                visited[i] = false; // 한 구역의 탐색이 끝났을 때, 방문여부를 false로 되돌려줘야 한다.
            }
        }
    }

    private ArrayList<String> getOperations(String expression) {
        ArrayList<String> ops = new ArrayList<>();

        if (expression.contains("+")) ops.add("+");
        if (expression.contains("-")) ops.add("-");
        if (expression.contains("*")) ops.add("*");

        return ops;
    }
}