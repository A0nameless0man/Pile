package MidtermTest;

public class TestB {
    public static class Circle {

        static public final Double PI = 3.141592653;

        public Circle() {
            r = 1;
        }

        public Circle(Integer radius) {
            r = radius;
        }

        public Double getArea() {
            return r * r * PI;
        }

        private Integer r;
    }

    public static void main(String[] args) {
        Circle r1 = new Circle();
        System.out.println(r1.getArea());
        Circle r2 = new Circle(10);
        System.out.println(r2.getArea());
    }
}