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
}
