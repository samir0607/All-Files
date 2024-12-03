public class ForEach {
  public static void main(String[] args) {
    //for-each: traverse through an array
    //          less flexible
    //          less steps, more readable
    String[] friends = {"satyam", "nikunj", "yash", "sarvesh", "shreyas"};
    for(String i: friends){
      System.out.println(i);
    }
  }
}
