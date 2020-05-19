package ScannerTest;

import java.io.DataOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;

public class FileIOStreamTest {
    static void write() {
        File f = new File("test.out");
        if (!f.exists()) {
            try {
                f.createNewFile();
            } catch (IOException e) {
                System.out.println("File creation fail");
                e.printStackTrace();
            }
        }
        try {
            DataOutputStream os = new DataOutputStream(new FileOutputStream(f));
            os.writeInt(42);
            os.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    static void read() {
        File f = new File("test.out");
        try {
            DataInputStream is = new DataInputStream(new FileInputStream(f));
            System.out.println(is.readInt());
            is.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    static void clean() {
        (new File("test.out")).delete();
    }

    public static void main(String[] args) {
        write();
        read();
        clean();
    }
}