#include "Dispatcher.h"
#include "Data.h"
#include "MatPoint.h"
#include "FileWriter.h"
#include "NetworkWriter.h"

namespace dynamics
{
	Dispatcher::Dispatcher(MatPoint& mat_point, FileWriter& file_writer, NetworkWriter& network_writer,
						   double end_time, double to_file_interval, double to_network_interval)
		: end_time_(end_time)
		, to_file_interval_(to_file_interval)
		, prev_file_time_(0)
		, to_network_interval_(to_network_interval)
		, prev_network_time_(0)
		, mat_point_(mat_point)
		, file_writer_(file_writer)
		, network_writer_(network_writer)
	{
	
	}

	void Dispatcher::DataHandler(Dispatcher& v, const KinValues& kin, bool write_first_call)
	{
		if (v.ShouldWrite(kin.t, v.prev_file_time_, v.to_file_interval_) || write_first_call)
		{
			v.file_writer_.PushQueque(kin);
;			v.prev_file_time_ = kin.t;
		}

		if (v.ShouldWrite(kin.t, v.prev_network_time_, v.to_network_interval_) || write_first_call)
		{	
			v.network_writer_.PushQueque(kin);
			v.prev_network_time_ = kin.t;
		}

	}
	bool Dispatcher::ShouldWrite(double t, double prev_rec_t, double rec_interval)
	{
		return (t - prev_rec_t >= rec_interval) ;
	}

	KinValues Dispatcher::Run()
	{
		KinValues result{0,0,0};
		
		std::thread thread_network([this]() {network_writer_.Run(); });
		std::thread thread_file([this]() {file_writer_.Run(); });
		
		mat_point_.TimeRun(end_time_, result);
		
		thread_file.join();
		thread_network.join();
		
		return result;
	}
}