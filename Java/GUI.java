
import javax.swing.JOptionPane;


public class GUI {

  public static void main(String[] args) {
    String name = JOptionPane.showInputDialog("What's your name?");
    JOptionPane.showMessageDialog(null,"Hello " +name);

    int age = Integer.parseInt(JOptionPane.showInputDialog("What's your age?"));
    JOptionPane.showMessageDialog(null,"You are " +age+ " years old");

    double height = Double.parseDouble(JOptionPane.showInputDialog("What's your height?"));
    JOptionPane.showMessageDialog(null,"Your height is " +height);
  }
}