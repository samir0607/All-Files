public class MethodOverriding {
  public static void main(String[] args) {
    // method-overriding = Declaring a method in sub-class, whichis is already present in parent class.
    //                      Done so that child can give its own implementation
    Animal animal = new Animal();
    animal.speak();
    Dog dog = new Dog();
    dog.speak();
  }
}
