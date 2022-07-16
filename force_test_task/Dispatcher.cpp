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

	void Dispatcher::IterationHandler(Dispatcher& v, const KinValues& kin, bool zero_iter)
	{
		if (v.ShouldWrite(kin.t, v.prev_file_time_, v.to_file_interval_) || true)
		{
			v.ToFile(kin);
		}

		if (v.ShouldWrite(kin.t, v.prev_network_time_, v.to_network_interval_) || true)
		{
			v.ToNetwork(kin);
		}
	}
	bool Dispatcher::ShouldWrite(double t, double prev_rec_t, double rec_interval)
	{
		return (t - prev_rec_t >= rec_interval) ;
	}
	
	void Dispatcher::ToFile(const KinValues& kin)
	{	
		if (ShouldWrite (kin.t, prev_file_time_, to_file_interval_))
		{
			prev_file_time_ = kin.t;
		}

		//v.add_line(const KinValues kin)
		// v.add_line(kin);
	}

	void Dispatcher::ToNetwork(const KinValues& kin) 
	{
	
    }
} 