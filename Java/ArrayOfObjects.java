public class ArrayOfObjects {

  public static void main(String[] args) {
    
    // Food[] refrigerator = new Food[4];

    Food food1 = new Food("Laphing");
    Food food2 = new Food("Mo:Mo:");
    Food food3 = new Food("Achar");
    Food food4 = new Food("Chowmein");

    Food[] refrigerator = {food1, food2, food3, food4};

    // refrigerator[0] = food1;
    // refrigerator[1] = food2;
    // refrigerator[2] = food3;
    // refrigerator[3] = food4;

    System.out.println(refrigerator[0].name);
    System.out.println(refrigerator[1].name);
    System.out.println(refrigerator[2].name);
    System.out.println(refrigerator[3].name);
  }
}