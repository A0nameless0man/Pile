package MainGroup;
//import java.math.BigInteger;
import java.math.*;
import java.util.Scanner;
//import java.io.*;
/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
       // BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        Scanner cin = new Scanner(System.in);
        System.out.println(Math.PI);
        BigInteger a=new BigInteger(cin.nextLine()),b=new BigInteger(cin.nextLine());
        String c = cin.nextLine();
        String d = cin.nextLine();
        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(c);
        System.out.println(d);
        cin.close();
    }
    public App()
    {
        System.out.println("App");
    }
}
