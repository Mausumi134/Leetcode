class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length;
        int n = mat[0].length;

        if (m * n != r * c) {
            return mat;
        }

        int[][] output = new int[r][c];

        int row = 0, col = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                output[row][col] = mat[i][j];
                col++;

                if (col == c) {
                    col = 0;
                    row++;
                }
            }
        }

        return output;
    }
}