#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "NetworkWriter.h"
#include <iostream>
#pragma comment(lib, "ws2_32.lib")

namespace dynamics
{
	NetworkWriter::NetworkWriter(const std::string& host, const int16_t port) : host_(host), port_(port)
	{
	}

	// В опциях проекта, в разделе Linker, в пункте Additional Dependancies укажите Ws2_32.lib

	bool NetworkWriter::UDPsender(const KinValues& kin)
	{

		in_addr ip_to_num;
		int r = inet_pton(AF_INET, host_.c_str(), &ip_to_num);
		if (r < 0)
		{
			std::cerr << "Функци inet_pton вернула ненулевой код возврата " << r;
			return false;
		}

		sockaddr_in serv_info;
		ZeroMemory(&serv_info, sizeof(serv_info));
		serv_info.sin_family = AF_INET;
		serv_info.sin_addr = ip_to_num;
		serv_info.sin_port = htons(port_);


		// Инициализация сокета
		WSADATA wsaData;
		r = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (r < 0)
		{
			std::cerr << "Функци WSAStartup вернула ненулевой код возврата " << r;
			//std::cerr << WSAGetLastError();
			return false;
		}
		// Create a SOCKET for connecting to server
		SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sock == INVALID_SOCKET)
		{
			std::cerr << "Функци socket вернула ненулевой код возврата " << sock;
			closesocket(sock);/////
			WSACleanup();
			return false;
		}


		r = connect(sock, (sockaddr*)&serv_info, sizeof(serv_info));

		if (r < 0)
		{
			std::cerr << "Функци connect вернула ненулевой код возврата " << r;
			closesocket(sock);/////
			WSACleanup();
			return false;
		}

		std::string data = kin_to_string(kin);
		// отправляем запрос на сервер
		r = send(sock, data.c_str(), data.size(), 0);

		if (r == SOCKET_ERROR) 
		{
			std::cerr << "Функци send вернула ненулевой код возврата " << r;
			closesocket(sock);/////
			WSACleanup();
			return false;
		}

		closesocket(sock);
		WSACleanup();

		return true;
	}
}