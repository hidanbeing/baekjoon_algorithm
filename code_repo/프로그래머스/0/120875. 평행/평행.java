class Solution {
    public int solution(int[][] dots) {

        int[][] s = {
            {0, 1, 2, 3},
            {0, 2, 1, 3},
            {0, 3, 1, 2}
        };

        for (int i=0; i<3; i++){
            if (parallel(dots[s[i][0]], dots[s[i][1]],
                         dots[s[i][2]], dots[s[i][3]])) {
                return 1;
            }
        }

        return 0;
    }

    // 두 선분의 기울기가 같은지(평행한지)
    public boolean parallel(int[] a, int[] b, int[] c, int[] d){
        int dy1 = b[1] - a[1];
        int dx1 = b[0] - a[0];
        int dy2 = d[1] - c[1];
        int dx2 = d[0] - c[0];

        return dy1 * dx2 == dy2 * dx1;
    }
}
