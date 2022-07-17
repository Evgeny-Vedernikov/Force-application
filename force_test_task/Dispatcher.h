#pragma once
#include "ParentWriter.h"
#include "FileWriter.h"
#include "NetworkWriter.h"
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{
	class Dispatcher 
	{
	public:
		Dispatcher(const std::string& host, int16_t port, const std::string& file_name, double to_file_interval,
			double to_network_interval, double end_time);
		~Dispatcher() = default;

			static void DataHandler(Dispatcher& v, const KinValues& kin, bool zero_iter);
			bool ShouldWrite(double t, double prev_time, double rec_interval);

	private:
		double to_file_interval_;
		double to_network_interval_;
		double prev_file_time_;
		double prev_network_time_;
		FileWriter file_writer_;
		NetworkWriter network_writer_;
	};
}