
import java.util.Random;


public class random {
  public static void main(String[] args) {
    Random random = new Random();
    int x = random.nextInt(6)+1;
    double y = random.nextDouble(8)+1;
    boolean z = random.nextBoolean();
    System.out.println(z);
  }
}
