#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <unistd.h>

int main()
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		std::cout << "socket creation failed." << "\n";
		return 0;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	int sock_addr =  inet_pton(AF_INET, "192.168.0.218", &addr.sin_addr);
	socklen_t addr_size = sizeof(addr);
	int sock_bind = bind(fd,(struct sockaddr *) &addr , addr_size);
	if( sock_bind == -1) {
		std::cout << "socket failed to bind" << "\n";
		return 0;
	}
		std::cout << "socket bound!"<< "\n";
	int listen_result = listen(fd, 1000);
	if (listen_result == 0) {
		std::cout << "Listening on port 8080 on localhost" << "\n";
	} else {
		std::cout << "failure to listen on socket" << "\n";
		return 0;
	}
	
	while (true) {
		struct sockaddr client;
		socklen_t client_len = sizeof(client);

		int sock_accept = accept(fd, &client, &client_len );
	
		if (sock_accept == -1) {
			std::cout << "Error has occured with accepting client request." << "\n";
			continue;
		}

		const char* html_content = "Welcome to ur mom chat";

		int htmlsize = strlen(html_content);
		int sent_bytes = send(sock_accept, html_content, htmlsize, 0);
		while (true) {
			char buffer[1024];
			if (int recieved_message = recv(sock_accept, buffer, sizeof(buffer), 0) > 0) {
				std::cout << buffer << "\n";
			}
		}
		close(sock_accept);
	}


	return 0;
}
