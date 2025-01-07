
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;


public class App {
    public static void main(String[] args) throws Exception {
        // JOptionPane = pop uo a standard dialog box that prompts users for a value or informs them of something.


        // JOptionPane.showMessageDialog(null,"This is some useless info","title", JOptionPane.PLAIN_MESSAGE);
        // JOptionPane.showMessageDialog(null,"This is some useless info","title", JOptionPane.INFORMATION_MESSAGE);
        // JOptionPane.showMessageDialog(null,"This is some useless info","title", JOptionPane.QUESTION_MESSAGE);
        // JOptionPane.showMessageDialog(null,"This is some useless info","title", JOptionPane.WARNING_MESSAGE);
        // JOptionPane.showMessageDialog(null,"This is some useless info","title", JOptionPane.ERROR_MESSAGE);

        //int answer = JOptionPane.showConfirmDialog(null,"bro do you even code?","title", JOptionPane.YES_NO_CANCEL_OPTION);
        //string name = JOptionPane.showInputDialog("What is your name?");

        String[] responses = {"No, you're cute!!", "thank you bunny", "Blush"};
        ImageIcon icon = new ImageIcon("/Users/rahulgupta/Desktop/bunny.png");
        Image resize = icon.getImage().getScaledInstance(40, 40, Image.SCALE_SMOOTH);
        icon = new ImageIcon(resize);
        JOptionPane.showOptionDialog(null, "Hey Handsome", "Secret", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.INFORMATION_MESSAGE, icon, responses, 0);
    }
}
