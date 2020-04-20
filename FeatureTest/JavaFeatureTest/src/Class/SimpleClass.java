package Class;

public class SimpleClass {
    public static class Circle {
        public static final Double PI = 3.1415927;
        public static final Double EXP = 1e-8;

        private Double r;

        public Circle() {
            this(1);
        }

        public Circle(double r) {
            this.r = r;
        }

        Circle(Integer r) {
            this.r = (double) (r);
        }

        public Double getRadious() {
            return r;
        }

        public Circle setRadious(Integer r) {
            return this.setRadious((double) r);
        }

        public Circle setRadious(Double r) {
            this.r = r;
            return this;
        }

        public Double getArea() {
            return area(r);
        }

        public static Double area(Double r) {
            return PI * r * r;
        }

        public static Boolean test() {
            Circle c1 = new Circle();
            assert c1.getRadious() == 1.0 : "Default radious is 1";
            Circle c2 = c1.setRadious(2.0);
            assert c2 == c1 : "setRadious returns Same Object";
            c2 = new Circle(2);
            Circle c3 = new Circle(2.0);
            assert (c2.getArea() - c3.getArea() < EXP);
            assert (Circle.area(2.0) - c3.getArea() < EXP);
            System.out.println(c2.getArea().toString());
            Double d = 1.0;
            Circle c4 = new Circle(d);
            d = 2.0;
            assert (Circle.area(1.0) - c4.getArea() < EXP);
            return true;
        }
    }

    public static void main(String[] args) {
        assert Circle.test() : "Test Fail";
        System.out.println("Test Finish");
    }
}