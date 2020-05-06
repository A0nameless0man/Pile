package FileTest;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class FileClassTest {
    public static void main(String[] args) {
        File f = new File("test.out");
        if (!f.exists()) {
            try {
                f.createNewFile();
            } catch (IOException e) {
                System.out.println("Can't Creat File");
                e.printStackTrace();
            }
        }
        if (f.exists()) {
            System.out.println("We got file");
            f.delete();
        }
        if(!f.exists())
        {
            System.out.println("deleted");
        }
    }
}