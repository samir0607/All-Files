public class StaticKeyword {
  public static void main(String[] args) {
    //static = modifiers. A single copy of variable/method is created and shared
    //          The class "owns" the static member
    Friend friend1 = new Friend("Yash");
    Friend friend2 = new Friend("Sarvesh");
    Friend.displayFriends();
  }
}
