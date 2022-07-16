#include <iostream>
#include <fstream>
#include "Dispatcher.h"
namespace dynamics
{
	Dispatcher::Dispatcher(const std::string& host, int16_t port, const std::string& file_name, double to_file_interval,
		 double to_network_interval) 
		: host_(host)
		, port_(port)
		, file_name_(file_name)
		, to_file_interval_(to_file_interval)
		, to_network_interval_(to_network_interval)
		, prev_file_time_(0)
		, prev_network_time_(0)
	{
	
	}

	void Dispatcher::IterationHandler(Dispatcher& v, const KinValues& kin)
	{	
		if (ShouldWrite(kin.t, prev_file_time_, to_file_interval_) )||  zero_iter
		{
			v.ToFile(kin);
		}

		if (ShouldWrite(kin.t, prev_network_time_, to_network_interval_) ) || zero_iter
		{
			v.ToUDP(kin);
		}

	bool Dispatcher::Should_Write(double prev_time, double rec_interval) 
	{
		return (kin.t - prev_time >= rec_interval) ;
	}
	
	void Dispatcher::ToFile(Dispatcher& v, const KinValues& kin)
	{	
		if (Should_Write (prev_file_time_, to_file_interval_))
		{
			prev_file_time_ = kin.t
		};

		//v.add_line(const KinValues kin)
		// v.add_line(kin);
	}

	void Dispatcher::ToUDP(Dispatcher& v, const KinValues& kin) 
	{
	
    }
} 