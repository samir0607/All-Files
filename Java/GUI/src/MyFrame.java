import java.awt.Color;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class MyFrame extends JFrame {

    MyFrame(){
        this.setTitle("JFrame Haha");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//exit out of app
        this.setResizable(false);//prevents from resizing
        this.setSize(400,400);//sets height and width of the frame
        this.setVisible(true); //makes frame visible
        ImageIcon image = new ImageIcon("/Users/rahulgupta/Desktop/tree.png");
        Image resize = image.getImage().getScaledInstance(100, 100, java.awt.Image.SCALE_SMOOTH);
        this.setIconImage(image.getImage()); //change icon of frame
        this.getContentPane().setBackground(new Color(38,50,87));
    }
  
}
