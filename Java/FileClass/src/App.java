import java.io.File;

public class App {
    public static void main(String[] args) {
        //file = An abstract representation of file and directory pathname
        File file = new File("FileClass/secret_message.rtf");

        if (file.exists()) {
            System.out.println("That file exists!");
            System.out.println(file.getPath());
            System.out.println(file.getAbsolutePath());
            System.out.println(file.isFile());
            file.delete();
        }
        else {
            System.out.println("That file doesn't exist");
        }
    }
}
