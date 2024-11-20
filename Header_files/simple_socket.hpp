#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

class Socket {
private:
  int socket_repns;
  struct sockaddr_in address_in;

public:
  void create(int type) {
    socket_repns = socket(AF_INET, type, 0);
    if (socket_repns < 0) {
      throw runtime_error("Failed to create socket");
    }
  }

  void bind_socket(const string& ip, int port) {
    address_in.sin_family = AF_INET;
    address_in.sin_port = htons(port);
    address_in.sin_addr.s_addr = inet_addr(ip.c_str());
    if (bind(socket_repns, (struct sockaddr*)&address_in, sizeof(address_in)) < 0) {
      throw runtime_error("Unable to bind socket");
    }
  }

  void listen_socket(int backlog) {
    if (listen(socket_repns, backlog) < 0) {
      throw runtime_error("Unable to listen on socket");
    }
  }

  Socket accept_socket() {
    Socket new_socket;
    socklen_t addr_size = sizeof(address_in);
    new_socket.socket_repns = accept(socket_repns, (struct sockaddr*)&address_in, &addr_size);
    if (new_socket.socket_repns < 0) {
      throw runtime_error("Unable to accept connection");
    }
    return new_socket;
  }

  void connect_to(const string& ip, int port) {
    address_in.sin_family = AF_INET;
    address_in.sin_port = htons(port);
    address_in.sin_addr.s_addr = inet_addr(ip.c_str());
    if (connect(socket_repns, (struct sockaddr*)&address_in, sizeof(address_in)) < 0) {
      throw runtime_error("Unable to connect");
    }
  }

  void send_message(const string& data) {
    if (send(socket_repns, data.c_str(), data.size(), 0) < 0) {
      throw runtime_error("Unable to send message");
    }
  }

  string receive(int buffer_size) {
    char buffer[buffer_size];
    int bytes_received = recv(socket_repns, buffer, buffer_size, 0);
    if (bytes_received < 0) {
      throw runtime_error("Unable to receive message");
    } else if (bytes_received == 0) {
      throw runtime_error("Server closed the connection");
    }
    return string(buffer, bytes_received);
  }

  void close_connection() {
    if (socket_repns != 0) {
      close(socket_repns);
      socket_repns = -1;
    }
  }

  ~Socket() {
    close_connection();
  }
};

#endif
