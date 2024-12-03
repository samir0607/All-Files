public class Inheritance {
  public static void main(String[] args) {
    Car1 car1 = new Car1();
    Bicycle1 bicycle1 = new Bicycle1();
    car1.go();
    bicycle1.stop();
    System.out.println(bicycle1.speed);
    System.out.println(car1.wheels);
    System.out.println(bicycle1.wheels);
  }
}
