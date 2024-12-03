public class OOPsConstructor {
  public static void main(String[] args) {
   Human human = new Human("Samir", 20, 75);
   Human human2 = new Human("Sanjana", 20, 48);
   System.out.println(human.name);
   System.out.println(human2.name);
   human.lover();
   human2.jaan();
  }
}
