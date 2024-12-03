import java.util.ArrayList;

public class ArrayList2D {
  public static void main(String[] args) {
    ArrayList<ArrayList<String>> groceryList = new ArrayList();
    ArrayList<String> bakeryList = new ArrayList();
    bakeryList.add("pasta");
    bakeryList.add("bread");
    bakeryList.add("chicken sandwich");

    ArrayList<String> snackList = new ArrayList();
    snackList.add("chips");
    snackList.add("kurkure");
    snackList.add("French Fry");

    ArrayList<String> dinnerList = new ArrayList();
    dinnerList.add("daal");
    dinnerList.add("roti");
    dinnerList.add("rice");

    groceryList.add(bakeryList);
    groceryList.add(snackList);
    groceryList.add(dinnerList);

    System.out.println(groceryList.get(0).get(2));
  }
}
