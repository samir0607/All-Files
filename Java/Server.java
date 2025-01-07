import java.io.*;
import java.net.*;
public class Server {
public static void main(String[] args) {
try (ServerSocket serverSocket = new ServerSocket(8080)) {
System.out.println("Server is listening on port 8080");
// Wait for client connection
Socket socket = serverSocket.accept();
System.out.println("Client connected");

// Set up input and output streams
DataInputStream input = new DataInputStream(socket.getInputStream());
DataOutputStream output = new DataOutputStream(socket.getOutputStream());

// Send a message to the client
output.writeUTF("Hello, Samir!");

// Read client's response
String message = input.readUTF();

System.out.println("Received from client: " + message);

// Close connections
socket.close();
} catch (IOException e) {
e.printStackTrace();
}
}
}