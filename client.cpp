#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

int main() {
	int client_sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	int sock_addr = inet_pton(AF_INET,"192.168.0.218", &addr.sin_addr);
	int addr_len = sizeof(addr);
	char msg[1024];
	if (connect(client_sock, (struct sockaddr *) &addr, addr_len) != -1) {
		int recieved_msg = recv(client_sock, msg, 1024, 0);
		std::cout << msg << "\n";
		while (true) {
		char sent_msg[1024];
		memset(sent_msg, 0, 1024);
		std::cin >> sent_msg;
		int wrotebits = write(client_sock, sent_msg, 1024);
		}
		shutdown(client_sock, SHUT_WR);
	}
	return 0;
}
