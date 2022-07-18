#pragma once

#include <queue>
#include <string>

namespace dynamics
{
	struct KinValues;
	class  MatPoint;
	class  FileWriter;
	class  NetworkWriter;

	class Dispatcher 
	{
	public:
		Dispatcher(MatPoint& mat_point, FileWriter& file_writer, NetworkWriter& network_writer,
				   double end_time, double to_file_interval, double to_network_interval);
		~Dispatcher() = default;
			
		bool should_write(double t, double prev_time, double rec_interval);
		KinValues run();

		static void data_handler(Dispatcher& v, const KinValues& kin, bool zero_iter);

	private:
		double end_time_;
		double to_file_interval_;
		double prev_file_time_;
		double to_network_interval_;
		double prev_network_time_;
		MatPoint& mat_point_;
		FileWriter& file_writer_;
		NetworkWriter& network_writer_;
	};
}