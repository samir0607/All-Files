import java.io.FileWriter;
import java.io.IOException;

public class fileWriter {
  public static void main(String[] args) {
    try{
      FileWriter writer = new FileWriter("poem.txt");
      writer.write("Roses are red\nViolets are blue");
      writer.append("\nOmayemo sindairu");
      writer.close();
    }
   catch(IOException e){
    e.printStackTrace();
   }
  }
}
