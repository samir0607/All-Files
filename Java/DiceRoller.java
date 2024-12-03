import java.util.Random;


public class DiceRoller {
  Random random;
  int num;
  DiceRoller(){
    random = new Random();
    num = 0;
    roll();
  }
  void roll(){
    num = random.nextInt(6)+1;
    System.out.println(num);
  }
}
