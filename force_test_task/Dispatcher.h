#pragma once
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{

	class  MatPoint;
	class  FileWriter;
	class  NetworkWriter;

	class Dispatcher 
	{
	public:
		Dispatcher(MatPoint& mat_point, FileWriter& file_writer, NetworkWriter& network_writer,
				   double end_time, double to_file_interval, double to_network_interval);
		~Dispatcher() = default;

			static void DataHandler(Dispatcher& v, const KinValues& kin, bool zero_iter);
			bool ShouldWrite(double t, double prev_time, double rec_interval);

	private:
		double to_file_interval_;
		double prev_file_time_;
		double to_network_interval_;
		double prev_network_time_;
		MatPoint& mat_point_;
		FileWriter& file_writer_;
		NetworkWriter& network_writer_;
	};
}