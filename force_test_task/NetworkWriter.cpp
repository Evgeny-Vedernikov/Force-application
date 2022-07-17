#include "NetworkWriter.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

namespace dynamics
{
	NetworkWriter::NetworkWriter(double end_time, const std::string& host, const int16_t port)
		: ParentWriter(end_time)
		, host_(host)
		, port_(port)
	{
	}

	bool NetworkWriter::Sender(const std::string& data_str)
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

		// Инициализация библиотеки сокетов
		WSADATA wsaData;
		r = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (r < 0)
		{
			std::cerr << "Функци WSAStartup вернула ненулевой код возврата " << r;
			//std::cerr << WSAGetLastError();
			return false;
		}
		// создаём сокет для UDP-клиента
		SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sock == INVALID_SOCKET)
		{
			std::cerr << "Функци socket вернула ненулевой код возврата " << sock;
			closesocket(sock);
			WSACleanup();
			return false;
		}

		r = connect(sock, (sockaddr*)&serv_info, sizeof(serv_info));

		if (r < 0)
		{
			std::cerr << "Функци connect вернула ненулевой код возврата " << r;
			closesocket(sock);
			WSACleanup();
			return false;
		}

		// отправляем данные на сервер
		r = send(sock, data_str.c_str(), static_cast<int>(data_str.size()), 0);

		if (r == SOCKET_ERROR) 
		{
			std::cerr << "Функци send вернула ненулевой код возврата " << r;
			closesocket(sock);
			WSACleanup();
			return false;
		}

		closesocket(sock);
		WSACleanup();

		return true;
	}
}