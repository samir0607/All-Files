
import java.awt.Color;
import java.awt.Font;
import java.awt.HeadlessException;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MyFrame1 extends JFrame implements ActionListener{
  JButton button;
  JLabel label;

    public MyFrame1() throws HeadlessException {

      ImageIcon icon = new ImageIcon("/Users/rahulgupta/Desktop/tree.png");
      Image resized = icon.getImage().getScaledInstance(180,100,java.awt.Image.SCALE_SMOOTH);
      icon = new ImageIcon(resized);
      ImageIcon icon2 = new ImageIcon("/Users/rahulgupta/Desktop/bunny.png");
      Image resized2 = icon2.getImage().getScaledInstance(180,100,java.awt.Image.SCALE_SMOOTH);
      icon2 = new ImageIcon(resized2);

      label = new JLabel("Label");
      label.setBounds(100,100,150,150);
      label.setVisible(false);

      button = new JButton();
      button.setBounds(200,100,250,250);
      button.addActionListener(this);
      button.setText("I'm a button");
      button.setFocusable(false);
      button.setIcon(icon);
      button.setHorizontalTextPosition(JButton.CENTER);
      button.setVerticalTextPosition(JButton.BOTTOM);
      button.setFont(new Font("Comic Sans", Font.BOLD,25));
      button.setIconTextGap(-10);
      button.setBackground(Color.lightGray);
      button.setForeground(Color.MAGENTA);
      button.setOpaque(true);

      button.setBorder(BorderFactory.createEtchedBorder());
      this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      this.setLayout(null);
      this.setSize(500,500);
      this.setVisible(true);
      this.add(button);
      this.add(label);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
      if(e.getSource()==button){
        System.out.println("poo");
        //button.setEnabled(false);
        label.setVisible(true);
      }
    }

  
}