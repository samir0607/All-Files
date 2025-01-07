import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 8080)) {
            System.out.println("Connected to server");

            // Set up input and output streams
            DataInputStream input = new DataInputStream(socket.getInputStream());
            DataOutputStream output = new DataOutputStream(socket.getOutputStream());

            // Read message from the server

            String message = input.readUTF();
            System.out.println("Received from server: " + message);

            // Send a response to the server
            output.writeUTF("Hello, Server!");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}