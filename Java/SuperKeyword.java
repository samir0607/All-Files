public class SuperKeyword {
  public static void main(String[] args) {
    // super = keyword refers o the superclass (parent) of an object
    //        very similar to "this" keyword
    Hero hero1 = new Hero("Batman", 42, "rich");
    Hero hero2 = new Hero("Superman", 43, "everything");
    
    System.out.println(hero2.toString());
  }
}
