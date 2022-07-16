#pragma once
#include "AbstractWriter.h"
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{
	class Dispatcher 
	{
	public:
		Dispatcher(const std::string& host, int16_t port, const std::string& file_name, double to_file_interval,
			double to_network_interval);
		~Dispatcher() = default;

			void IterationHandler(Dispatcher& v, const KinValues& kin);
			void ToFile(const KinValues& kin);
			void ToUDP( const KinValues& kin);
			bool ShouldWrite(const double time, const double prev_time, const double rec_interval);

	protected:

	private:
		std::string host_;
		int16_t port_;
		std::string file_name_;
		double to_file_interval_;
		double to_network_interval_;
		double prev_file_time_;
		double prev_network_time_;
	};
}