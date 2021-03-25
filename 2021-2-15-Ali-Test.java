public class Main {
    public static void main(String[] args) {
        int[] res = new int[10];
        Stack<Integer> stack = new Stack<Integer>();
        int[] input = { 2, 5, 7, 3, 6, 4, 10, 1 };
        for (int i = input.length - 1; i >= 0; --i) {
            while (!stack.empty() && input[i] <= stack.peek()) {
                stack.pop();
            }
            if (stack.empty()) {
                res[input.length - i - 1] = -1;
            } else {
                res[input.length - i - 1] = stack.peek();
            }
            stack.push(input[i]);
        }
        System.out.println(res);
    }

}