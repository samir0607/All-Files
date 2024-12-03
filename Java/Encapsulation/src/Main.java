public class Main {
  public static void main(String[] args) {
    // Encapsulation = attributes of a class will be hidden or private,
    //                 Can be accessed through methods (getters and setters)
    //                 You should make attributes private if you don't have a reason to make them

    Car car1 = new Car("Lamborgini", "Avendator", 2019);

    car1.setYear(2022);

    System.out.println(car1.getMake());
    System.out.println(car1.getModel());
    System.out.println(car1.getYear());
  }
}
