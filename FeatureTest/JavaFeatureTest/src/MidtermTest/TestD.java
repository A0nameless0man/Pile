package MidtermTest;

public class TestD {
    public static class Outer {
        public class Inner {
            public Integer answer = 42;
        }

        public Inner getInner() {
            return new Inner();
            //外部类直接调用
        }
    }

    public static class Other {
        public void test() {
            Outer.Inner i = (new Outer()).getInner();
            //其它类通过外部类得到实例后调用
            System.out.println(i.answer);
        }
    }
    public static void main(String[] args) {
        (new Other()).test();
    }
}