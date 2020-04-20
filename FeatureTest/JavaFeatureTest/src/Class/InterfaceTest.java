package Class;

import java.util.Vector;

public class InterfaceTest {
    /**
     * Shape2D
     *
     */
    public interface Shape2D {

        public Double getArea();
    }

    public static class Vec2D implements Cloneable {
        public Vec2D(final Double x, final Double y) {
            this.x = x;
            this.y = y;
        }

        private final Double x, y;

        public static Vec2D sub(final Vec2D lop, final Vec2D rop) {
            return new Vec2D(lop.x - rop.x, lop.y - rop.y);
        }

        public static Double dex(final Vec2D lop, final Vec2D rop) {
            return lop.x * rop.y - lop.y * rop.x;
        }

        public Object clone() throws CloneNotSupportedException {
            return super.clone();
        }
    }

    public static class Triangle2D implements Shape2D, Cloneable {
        private final Vec2D a;
        private final Vec2D b;
        private final Vec2D c;

        public Triangle2D(final Vec2D a, final Vec2D b, final Vec2D c) throws CloneNotSupportedException {
            this.a = (Vec2D) a.clone();
            this.b = (Vec2D) b.clone();
            this.c = (Vec2D) c.clone();
        }

        public Triangle2D(final Vec2D b, final Vec2D c) throws CloneNotSupportedException {
            this(new Vec2D(0.0, 0.0), b, c);
        }

        public Double getArea() {
            return Math.abs(Vec2D.dex(Vec2D.sub(b, a), Vec2D.sub(c, a)))/2.0;
        }

        public Object clone() throws CloneNotSupportedException {
            return new Triangle2D(a, b, c);
        }
    }

    public static class Round implements Shape2D {
        public Round(final Double r) {
            this.r = r;
        }

        public Double getArea() {
            return SimpleClass.Circle.PI * r * r;
        }

        private final Double r;
    }

    public static class Square implements Shape2D {
        private Double s;

        Square(Double s) {
            this.s = s;
        }

        public Double getArea() {
            return s * s;
        }
    }

    public static void main(String[] args) {
        try {
            Vector<Shape2D> shapes = new Vector<Shape2D>();
            shapes.add(new Round(10.0));
            shapes.add(new Triangle2D(new Vec2D(0.0, 0.0), new Vec2D(1.0, 0.0), new Vec2D(0.0, 1.0)));
            shapes.add(new Square(10.0));
            for(Shape2D s:shapes)
            {
                System.out.printf("%s has area of %f\n",s.getClass(),s.getArea());
            }
        } catch (Exception e) {
            // DONE: handle exception
            e.printStackTrace();
        }
    }
}