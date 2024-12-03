public class App {
    public static void main(String[] args) {
        //interface =  a template that can be applied to a class.
        //             similar to inheritance, but specifies what a class has/must do.
        //             classes can apply more than one interface, inheritance is limited to 1 super class
        Rabbit rabbit = new Rabbit();
        rabbit.flee(); //implements only prey
        Hawk hawk = new Hawk();
        hawk.hunt();//implements only predator
        Fish fish = new Fish();
        fish.flee(); //implements both interfaces/templates(prey,predator)
        fish.hunt();
    }
}
