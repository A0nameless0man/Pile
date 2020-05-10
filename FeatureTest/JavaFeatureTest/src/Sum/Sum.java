package Sum;

// import HelloWorld.App;

public class Sum {
    public static void main(String[] args) {
        HelloWorld.App.main(args);
        {
            int sum = 0;
            int i = 1;
            while (i <= 100) {
                sum += i;
                ++i;
            }
            System.out.println("Sum is :" + (sum));
        }
        {
            int sum = 0;
            for (int i = 1; i <= 100; ++i) {
                sum += i;
            }
            System.out.println("Sum is :" + (sum));
        }
    }
}