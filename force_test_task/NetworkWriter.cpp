#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "NetworkWriter.h"


namespace dynamics
{
	NetworkWriter::NetworkWriter(const std::string& host, const int16_t port) : host_(host), port_(port)
	{
	}

	// � ������ �������, � ������� Linker, � ������ Additional Dependancies ������� Ws2_32.lib

	bool NetworkWriter::UDPsender(const KinValues& kin)
	{
		//WSADATA wsaData;
		//SOCKET SendRecvSocket;  // ����� ��� ������ � ��������
		//sockaddr_in ServerAddr;  // ��� ����� ����� ������� � ��������
		//int err, maxlen = 512;  // ��� ������, ������ ������� � ������ ��������� ������
		//char* recvbuf = new char[maxlen];  // ����� ������
		//char* query = new char[maxlen];  // ����� ��������


		//// Initialize Winsock
		//WSAStartup(MAKEWORD(2, 2), &wsaData);

		//// Create a SOCKET for connecting to server
		//SendRecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

		//ServerAddr.sin_family = AF_INET;
		//ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		//ServerAddr.sin_port = htons(port_);

		//_snprintf_s(query, maxlen, maxlen, "CALC * 12 6\n");
		//// ���������� ������ �� ������
		//sendto(SendRecvSocket, query, strlen(query), 0, (sockaddr*)&ServerAddr, sizeof(ServerAddr));
		//printf("Sent: %s\n", query);

		//// �������� ���������
		//err = recvfrom(SendRecvSocket, recvbuf, maxlen, 0, 0, 0);
		//if (err > 0) {
		//	recvbuf[err] = 0;
		//	printf("Result: %s\n", (char*)recvbuf);
		//}
		//else {
		//	printf("recv failed: %d\n", WSAGetLastError());
		//	closesocket(SendRecvSocket);
		//	WSACleanup();
		//}

		//closesocket(SendRecvSocket);

		return true;
	}
}