package FileTest;

import java.io.*;

public class FileStreamTest {
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
        try {

            DataInputStream is = new DataInputStream(new FileInputStream(f));
            DataOutputStream os = new DataOutputStream(new FileOutputStream(f));
            os.writeInt(42);
            System.out.println(is.readInt());
            is.close();
            os.close();

        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());

        }
        f.deleteOnExit();
    }
}