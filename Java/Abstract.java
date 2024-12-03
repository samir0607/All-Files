public class Abstract {
  public static void main(String[] args) {
    // abstract = abstract classes cannot be instantiated, but they can have a subclass
    //            abstract methods are declared without an implementation
    // Vehicle2 vehicle = new Vehicle2();
    Car2 car = new Car2();
    car.go();
  }
}
