package PackageTest.ProtectedMemberTest.PackageB;

public class ClassB extends PackageTest.ProtectedMemberTest.PackageA.ClassA{
    public void test()
    {
        System.out.println(answer);
    }
    public static void main(String[] args) {
        (new ClassB()).test();
    }
}