package ScannerTest;

import java.util.Scanner;

public class ScannerTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(input.hasNext())
        {
            System.out.println(input.next());
        }
        input.close();
    }
}