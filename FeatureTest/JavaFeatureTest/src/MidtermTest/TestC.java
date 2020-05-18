package MidtermTest;

public class TestC {
    public static class Member {
        static Integer s_m = 1;
        public Integer p_m = 1;

        // public Member()
        public static Integer s_f() {
            return s_m;
        }

        public Integer p_f() {
            return p_m;
        }
    }

    public static void main(String[] args) {
        Member m_1 = new Member();
        Member m_2 = new Member();
        m_1.p_m = 2;
        m_1.s_m = 2;
        System.out.println(m_2.s_m);
        System.out.println(m_2.p_m);
        System.out.println(m_2.p_f());
        System.out.println(m_2.s_f());
        Member.s_m = 5;
        System.out.println(Member.s_m);
        System.out.println(Member.s_f());
    }
}