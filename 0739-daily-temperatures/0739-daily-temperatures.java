class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];

        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
                answer[stack.peek()] = i - stack.pop();
            }

            stack.push(i);
        }
        
        return answer;
    }
}