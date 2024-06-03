#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main () {
  int server_sock_fd = -1; //intializing socket file descripter//
  struct sockaddr_in sock_addr;

  server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(server_sock_fd == 0) {
    printf("[failed]\n");
  }
  else {
    printf("[succes] socket_fd: %d\n", server_sock_fd);
  }

  memset(&sock_addr, 0, sizeof(sock_addr)); //set 0s to sock_addr.
  //defining socket addresses
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_addr.s_addr = INADDR_ANY;
  sock_addr.sin_port = htons(8080);
  
  printf("%d, %d, %d\n"), sock_addr.sin_family, sock_addr.sin_addr, sock_addr.sin_port;

  return 0;
}
