import java.util.*;

class Solution {
    int digitN;
    int answer;
    public int solution(int N, int number) {
        answer = Integer.MAX_VALUE;
        int[] x = new int[11];
        int tmpN = N;

        while (tmpN > 0) {
            tmpN /= 10;
            digitN++;
        }
        for (int i = 1; i <= 9; i+= digitN) {
            String tmp = "";
            for (int j = 0; j < i; j++) {
                tmp += N;
            }
            x[i] = Integer.valueOf(tmp);
        }

        dp(N, number, 0, 0, x);
        if (answer > 8) return -1;
        return answer;
    }
    
    private void dp(int N, int number, int cur, int count, int[] x) {
        if (count > 8 || (cur == 0 && count > 0)) {
            return;
        }
        if (cur == number) {
            answer = Math.min(answer, count);
        }
        for (int i = 1; i <= 9; i+= digitN) {
            dp(N, number, cur + x[i], count + i, x);
            dp(N, number, cur - x[i], count + i, x);
            dp(N, number, cur * x[i], count + i, x);
            dp(N, number, cur / x[i], count + i, x);
        }
    }
}