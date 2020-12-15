//reference from linux系統程式設計
/*
 * linux compile with gcc -o p2p p2p.c -I.
 * keyin something will send back the message
 *
 */

#include "general_include.h"
int main() {
	int peerSocket;
	struct sockaddr_in self_addr;
	struct sockaddr_in peer_Addr;
	int peer_len = sizeof(peer_Addr);

	char recvbuf[1024], sendbuf[1024];

	if ((peerSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket"); exit(1);
	}

	bzero(&self_addr, sizeof(self_addr));
	self_addr.sin_family = AF_INET;
	self_addr.sin_port = htons(SERVER_PORT);
	self_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(peerSocket, (struct sockaddr *)&self_addr, sizeof(self_addr)) < 0) {
		perror("connect"); exit(1);
	}

	while (1) {
		printf("Input your World:>");
		scanf("%s", sendbuf);
		sendto(peerSocket, sendbuf, 1024, 0, (struct sockaddr *)&self_addr, sizeof(self_addr));
		recvfrom(peerSocket, recvbuf, 1024, 0, (struct sockaddr *)&peer_Addr, (socklen_t*)&peer_len);
		printf("\nrecv from %s\n", recvbuf);
	}
}
