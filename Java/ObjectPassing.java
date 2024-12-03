public class ObjectPassing {
  public static void main(String[] args) {
    Garage garage = new Garage();
    Vehicle car1 = new Vehicle("Honda Civic");
    Vehicle car2 = new Vehicle("Tesla");
    garage.park(car2);
  }
}
