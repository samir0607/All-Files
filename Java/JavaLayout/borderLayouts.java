import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class borderLayouts {
    public static void main(String[] args) throws Exception {
        //Layout Manager = Defines the natural layout for components within a container
        // 3 common managers
        //BorderLayout = A BorderLayout places components in five areas: NORTH, SOUTH, WEST, EAST, CENTER.
        //               All extra spacce is placed in the center area.
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setLayout(new BorderLayout(10,10));
        
        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();
        JPanel panel3 = new JPanel();
        JPanel panel4 = new JPanel();
        JPanel panel5 = new JPanel();

        panel1.setBackground(Color.red);
        panel2.setBackground(Color.green);
        panel3.setBackground(Color.blue);
        panel4.setBackground(Color.yellow);
        panel5.setBackground(Color.magenta);

        panel1.setPreferredSize(new Dimension(100,100));
        panel2.setPreferredSize(new Dimension(100,100));
        panel3.setPreferredSize(new Dimension(100,100));
        panel4.setPreferredSize(new Dimension(100,100));
        panel5.setPreferredSize(new Dimension(100,100));

        //===================Sub Panels==============================

        JPanel panel10 = new JPanel();
        JPanel panel20 = new JPanel();
        JPanel panel30 = new JPanel();
        JPanel panel40 = new JPanel();
        JPanel panel50 = new JPanel();

        panel10.setBackground(Color.black);
        panel20.setBackground(Color.gray);
        panel30.setBackground(Color.darkGray);
        panel40.setBackground(Color.lightGray);
        panel50.setBackground(Color.white);

        panel5.setLayout(new BorderLayout());

        panel10.setPreferredSize(new Dimension(50,50));
        panel20.setPreferredSize(new Dimension(50,50));
        panel30.setPreferredSize(new Dimension(50,50));
        panel40.setPreferredSize(new Dimension(50,50));
        panel50.setPreferredSize(new Dimension(50,50));

        panel5.add(panel10, BorderLayout.NORTH);
        panel5.add(panel20, BorderLayout.SOUTH);
        panel5.add(panel30, BorderLayout.WEST);
        panel5.add(panel40, BorderLayout.EAST);
        panel5.add(panel50, BorderLayout.CENTER);
        //===========================================================

        frame.add(panel1,BorderLayout.NORTH);
        frame.add(panel2,BorderLayout.SOUTH);
        frame.add(panel3,BorderLayout.WEST);
        frame.add(panel4,BorderLayout.EAST);
        frame.add(panel5,BorderLayout.CENTER);

        frame.setVisible(true);
    }
}
