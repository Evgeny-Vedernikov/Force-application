#include <iostream>
#include <fstream>
#include "Dispatcher.h"
namespace dynamics
{
	Dispatcher::Dispatcher(const std::string& host, int16_t port, const std::string& file_name) 
		: host_(host)
		, port_(port)
		, file_name_(file_name)
	{
	
	}

	void Dispatcher::IterationHandler(Dispatcher& v, const KinValues& kin)
	{
		// v.add_line(kin);
	}
	

} 