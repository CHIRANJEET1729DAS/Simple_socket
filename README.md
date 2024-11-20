# One-to-One Chat Room (Socket-based Chat Application)

# Overview:

The One-to-One Chat Room is a basic but powerful real-time messaging application built using socket programming in C++. The project enables two users to establish a direct connection over a network and exchange messages in real time, mimicking a chat room environment where communication takes place between two parties.

This project is a simple demonstration of client-server communication using TCP/IP sockets, handling the process of establishing connections, sending and receiving messages, and closing connections once the communication is finished.

# Key Features:

1)Real-Time Messaging: The core feature of the application is its ability to allow users to send and receive messages instantly. Messages are exchanged between the client and server in real time, without any significant delay.

2)Server-Client Communication: The application follows a traditional server-client model. The server listens on a specific port for incoming client connections, while clients can connect to the server to send and receive messages.

3)User-defined Messages: Both the client and the server accept user-defined input. Clients can type their own messages, which are sent to the server and forwarded to the connected client.

4)Continuous Communication: Once a connection is established, both the client and the server can continue exchanging messages back and forth until either party decides to disconnect.

5)Graceful Disconnect: When either the client or server decides to end the conversation, they can close the connection gracefully, ensuring that all resources are freed, and the communication channel is properly closed.

# How It Works:

The application follows a simple client-server architecture built using TCP sockets. Here’s a breakdown of how the server and client work:

1) Server Side (Server.cpp):
Socket Creation: The server starts by creating a socket using the socket() system call. It specifies the use of IPv4 and TCP protocols.

2) Binding the Socket: The server binds its socket to a specific IP address and port number using the bind() system call. This is required to ensure that the server can receive incoming connections on that specific address and port.

3) Listening for Connections: After binding, the server listens for incoming client requests using the listen() system call. The server is capable of accepting connections from clients as they attempt to connect.

4) Accepting Clients: The server uses the accept() system call to accept incoming connections from clients. When a client connects, the server creates a new socket specifically for that client to handle the communication.

5) Message Relay: Once the connection is established, the server receives messages from the client and forwards them to the connected client. The communication is bidirectional, with messages flowing seamlessly from the server to the clients.

6) Graceful Disconnection: When the chat ends, the server can close the connection by calling close() on the socket, ensuring that all resources are freed up properly.

# Client Side (Client.cpp):

1) Socket Creation: The client also creates a socket using the socket() system call. Like the server, it uses IPv4 and TCP protocols to communicate with the server.

2) Connecting to Server: The client connects to the server using the connect() system call. It needs to specify the server’s IP address and the port on which the server is listening. If the connection is successful, the client can start sending and receiving messages.

3) Sending Messages: After connecting, the client can input messages that are sent to the server using the send() system call. The client’s messages are then relayed to the server and, from there, forwarded to the other client.

4) Receiving Messages: The client listens for incoming messages from the server using the recv() system call. Once a message is received, it is displayed to the user.

5) Graceful Disconnection: Once the conversation is over, the client can close the connection to the server using the close() system call.

# Technologies Used:
    C++ Programming Language: The entire application is written in C++, utilizing standard libraries and system calls 
    for networking operations.
    
    Socket Programming: The application uses TCP/IP socket programming to establish connections between the server and 
    client, send and receive messages, and handle communication.
    
    Unix-based System Calls: The project uses common Unix-based system calls such as socket(), bind(), listen(), 
    accept(), connect(), send(), and recv() for socket creation, communication, and disconnection.

# Components of the Project:

1) Socket Class (simple_socket.hpp): This class encapsulates the functionality needed to create and manage sockets, including methods for creating sockets, binding, listening, sending/receiving messages, and closing the connection. The Socket class is reused by both the server and client programs.

2) Server Program (Server.cpp): The server program initializes a server socket, listens for client connections, and facilitates message exchange between the client and the server.

3) Client Program (Client.cpp): The client program creates a socket to connect to the server, send user-defined messages, and receive responses from the server.
