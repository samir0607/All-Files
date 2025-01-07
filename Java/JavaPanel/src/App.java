import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class App {

    public static void main(String[] args) throws Exception{
        // JPanel = a GUI component that functions as a container to hold other components
        ImageIcon icon = new ImageIcon("logo.png");
        Image scaleImage = icon.getImage().getScaledInstance(200, 200,Image.SCALE_DEFAULT);
        icon = new ImageIcon(scaleImage);
       
        JLabel label = new JLabel();
        label.setText("Hi");//sets text
        label.setIcon(icon);// sets imageicon
        
        label.setVerticalAlignment(JLabel.TOP); //label's vertical alignment
        label.setHorizontalAlignment(JLabel.CENTER);
        
        JPanel redPanel = new JPanel();
        redPanel.setBackground(Color.red);
        redPanel.setBounds(0, 0, 250, 250); // Only works with null layout
        redPanel.setLayout(new BorderLayout());
        
        JPanel bluePanel = new JPanel();
        bluePanel.setBackground(Color.blue);
        bluePanel.setBounds(250, 0, 250, 250); 
        bluePanel.setLayout(new BorderLayout());
        
        JPanel greenPanel = new JPanel();
        greenPanel.setBackground(Color.green);
        greenPanel.setBounds(0, 250, 500, 250); 
        greenPanel.setLayout(new BorderLayout());
        
        
        
        // Create frame
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        frame.setSize(750, 750);
        frame.setVisible(true);
		greenPanel.add(label);
        frame.add(redPanel);
        frame.add(bluePanel);
        frame.add(greenPanel);
    }
}
