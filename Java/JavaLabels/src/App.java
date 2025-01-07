import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.border.Border;


public class App {
    public static void main(String[] args) throws Exception {
        // Jlabel = a GUI display area for a string of text, an image, or both

        ImageIcon image = new ImageIcon("/Users/rahulgupta/Desktop/bunny.png");
        Image newimg = image.getImage().getScaledInstance(500, 500, java.awt.Image.SCALE_SMOOTH); //for image resizing
        image = new ImageIcon(newimg);
       
        Border border = BorderFactory.createSoftBevelBorder(5); //border component
        
        JLabel label = new JLabel();
        label.setText("My Bunny");//sets text
        label.setIcon(image);// sets imageicon
        label.setHorizontalTextPosition(JLabel.CENTER); //set text Left, center, right of image icon
        label.setVerticalTextPosition(JLabel.TOP);// set text top, bottom or center of image
        label.setForeground(Color.PINK); //sets text color
        label.setFont(new Font("MV Boli",Font.PLAIN,20)); //sets font to text
        label.setIconTextGap(20); //Gap between text and image
        label.setBackground(new Color(130,10,70)); //background color
        label.setOpaque(true); //to make the background visible
        label.setBorder(border);//sets border
        label.setVerticalAlignment(JLabel.CENTER); //label's vertical alignment
        label.setHorizontalAlignment(JLabel.CENTER); //label's horizontal alignment
        //label.setBounds(100,100,250,250);
        
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //frame.setSize(500,500);
       // frame.setLayout(null);
        frame.setVisible(true);
        frame.add(label);
        frame.pack();//always pack after adding all the components
    }
}
