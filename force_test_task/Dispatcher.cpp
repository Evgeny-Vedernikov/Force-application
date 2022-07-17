#include <iostream>
#include <fstream>
#include "Dispatcher.h"
#include "FileWriter.h"
namespace dynamics
{
	Dispatcher::Dispatcher(const std::string& host, int16_t port, const std::string& file_name, double to_file_interval,
		 double to_network_interval, double end_time)
		: to_file_interval_(to_file_interval)
		, to_network_interval_(to_network_interval)
		, prev_file_time_(0)
		, prev_network_time_(0)
		, file_writer_(end_time, file_name)
		, network_writer_(end_time, host, port)
	{
	
	}

	void Dispatcher::DataHandler(Dispatcher& v, const KinValues& kin, bool write_first_call)
	{
		if (v.ShouldWrite(kin.t, v.prev_file_time_, v.to_file_interval_) || write_first_call)
		{
			//v.ToFile(kin);
			v.file_writer_.PushQueque(kin);
;			v.prev_file_time_ = kin.t;
		}

		if (v.ShouldWrite(kin.t, v.prev_network_time_, v.to_network_interval_) || write_first_call)
		{	
			//v.ToNetwork(kin);
			v.network_writer_.PushQueque(kin);
			v.prev_network_time_ = kin.t;
		}
	}
	bool Dispatcher::ShouldWrite(double t, double prev_rec_t, double rec_interval)
	{
		return (t - prev_rec_t >= rec_interval) ;
	}
	

} 