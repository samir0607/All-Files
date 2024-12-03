import java.util.Scanner;

public class scanner{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    System.out.println("What's your name?");
    String name = scanner.nextLine();
    System.out.println("What's your age?");
    int age = scanner.nextInt();
    scanner.nextLine();
    System.out.println("What's your school name?");
    String school = scanner.nextLine();

    System.out.println("Hello "+name);
    System.out.println("You are "+age+" years old");
    System.out.println("You read in "+school);

  }
}