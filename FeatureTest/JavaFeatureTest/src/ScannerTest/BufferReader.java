package ScannerTest;

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class BufferReader {
    public static void main(String[] args) {
        BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
        try {
            while (true) {
                System.out.println(bfr.readLine());
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}