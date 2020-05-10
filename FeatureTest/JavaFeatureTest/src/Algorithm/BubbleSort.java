package Algorithm;

import java.util.*;

import Class.SimpleClass.*;

public class BubbleSort {
    /**
     * Sortable<T>
     */
    public interface Sortable<T> extends Comparable<T> {

    }

    public static <T extends Sortable<T>, L extends List<T>> void bSort(L list) {
        Vector<T> ary = new Vector<T>();
        ary.addAll(list);
        for (int i = 0; i < ary.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (ary.get(i).compareTo(ary.get(j)) < 0) {
                    T t = ary.get(i);
                    ary.set(i, ary.get(j));
                    ary.set(j, t);
                }
            }
        }
        list.clear();
        list.addAll(ary);
    }

    /**
     * Triangle
     */
    public interface Shape2D {

        public Double getArea();
    }

    static abstract public class SortableShape2D implements Shape2D, Sortable<SortableShape2D> {
        abstract public Double getArea();

        public int compareTo(SortableShape2D rop) {
            return this.getArea().compareTo(rop.getArea());
        }
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

    public static class Triangle2D extends SortableShape2D implements Cloneable {
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
            return Math.abs(Vec2D.dex(Vec2D.sub(b, a), Vec2D.sub(c, a))) / 2.0;
        }

        public Object clone() throws CloneNotSupportedException {
            return new Triangle2D(a, b, c);
        }
    }

    public static class Round extends SortableShape2D {
        public Round(final Double r) {
            this.r = r;
        }

        public Double getArea() {
            return Circle.PI * r * r;
        }

        private final Double r;
    }

    public static class Square extends SortableShape2D {
        private Double s;

        Square(Double s) {
            this.s = s;
        }

        public Double getArea() {
            return s * s;
        }
    }

    public static void main(String[] args) {
        Vector<SortableShape2D> vec = new Vector<SortableShape2D>();
        for (Integer i = 0; i < 10; ++i) {
            vec.add(new Square((double) i));
        }
        for (Integer i = 0; i < 10; ++i) {
            vec.add(new Round((double)i));
        }
        Collections.shuffle(vec);
        for (SortableShape2D i : vec) {
            System.out.printf("%f %s\n", i.getArea(),i.getClass().getSimpleName());
        }
        System.out.println("");
        bSort(vec);
        for (SortableShape2D i : vec) {
            System.out.printf("%f %s\n", i.getArea(), i.getClass().getSimpleName());
        }
        System.out.println("");
    }
}