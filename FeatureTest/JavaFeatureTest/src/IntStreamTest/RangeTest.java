package IntStreamTest;

import java.util.stream.IntStream;

public class RangeTest
{
    public static void main(String[] args) {
        System.out.println("Sum is "+(IntStream.rangeClosed(1,100).sum()));
    }
}