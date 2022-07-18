#include "ParentWriter.h"
#include <iomanip>
#include <sstream>
#include <thread>
#include <atomic>

namespace dynamics
{
	ParentWriter::ParentWriter(double arg_end_time) : end_time(arg_end_time), cur_time(0), q(), mtx()
	{
	}

	std::string ParentWriter::kin_to_string(const KinValues& kin)
	{
		std::stringstream s;
		std::int8_t precision = 6;

		s << std::fixed << std::setprecision(precision) << "t = "
			<< std::setw(precision+3) << kin.t << "    V = "
			<< std::setw(precision+4) << kin.v << "    s = "
			<< std::setw(precision+5) << kin.s << std::endl;
		return s.str();
	}

	void ParentWriter::push_queue(const KinValues& kin)
	{
		std::lock_guard<std::mutex> lock(mtx);
		q.push (kin);
	}

	void ParentWriter::run ()
	{
		while (cur_time <= end_time )
		{
			if (!q.empty())
			{
				KinValues kin_data = pop_queue();
				sender(kin_to_string(kin_data));
				cur_time = kin_data.t;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		}
	}

	KinValues ParentWriter::pop_queue()
	{	
		KinValues result;
		{
			std::lock_guard<std::mutex> lock(mtx);
			result = q.front();
			q.pop();
		}
		return 	result;
	}
}