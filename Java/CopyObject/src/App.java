public class App {
    public static void main(String[] args) {
        Car car1 = new Car("Ford", "Mustang", 2019);

        //car2 = car1 (don't do this)
       // car2.copy(car1);
        Car car2 = new Car(car1);
        
        System.out.println(car1);
        System.out.println(car2);
        System.out.println();
        System.out.println(car1.getMake());
        System.out.println(car1.getModel());
        System.out.println(car1.getYear());
        System.out.println();
        System.out.println(car2.getMake());
        System.out.println(car2.getModel());
        System.out.println(car2.getYear());
    }
}
