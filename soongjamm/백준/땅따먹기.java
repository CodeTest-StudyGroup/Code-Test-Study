import java.util.Arrays;

public class 땅따먹기 {

    static int solution(int[][] land) {
        int[][] memory = new int[land.length][4];

        for (int row = 0; row < land.length; row++) {
            for (int past = 0; past < 4; past++) {
                if (row == 0) {
                    memory[0][past] = land[0][past];
                    continue;
                }

                for (int col = 0; col < 4; col++) {
                    if (past == col) {
                        continue;
                    }
                    memory[row][col] = Math.max( memory[row-1][past] + land[row][col] , memory[row][col] );
                }
            }
        }

        int max = 0;
        for (int i=0; i<4; i++) {
            max = Math.max(max, memory[land.length-1][i]);
        }
        return max;
    }


    public static void main(String[] args) {
        int[][] arr = {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
        int[][] arr2 = {{1, 1, 1, 5}, {0, 0, 0, 100}, {1, 2, 3, 4}, {4, 3, 3, 1}};

        System.out.println(solution(arr) == 16);
        System.out.println(solution(arr2));
    }
}
