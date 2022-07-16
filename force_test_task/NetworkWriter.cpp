#include <iostream>
#include <fstream>
#include "NetworkWriter.h"

namespace dynamics
{
	NetworkWriter::NetworkWriter(const std::string& host, const int16_t port) : host_(host), port_(port)
	{
	}

	//void NetworkWriter::add_line(const KinValues kin) const {}

} 

