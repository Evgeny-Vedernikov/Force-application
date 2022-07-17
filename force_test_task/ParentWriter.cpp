#include "ParentWriter.h"
#include <iomanip>
#include <sstream>
#include <thread>
#include <atomic>

namespace dynamics
{
	ParentWriter::ParentWriter(double a_end_time) : cur_time(0), end_time(a_end_time), q(), mtx()
	{
	}

	std::string ParentWriter::KinToString(const KinValues& kin) 
	{
		std::stringstream s;  // поток для записи
		std::int8_t prec = 14;

		s << std::fixed << std::setprecision(prec) << "t = " 
			<< std::setw(prec+3) << kin.t << "    V = " 
			<< std::setw(prec+4) << kin.v << "    x = "
			<< std::setw(prec+5) << kin.x << std::endl;
		return s.str();
	}

	void ParentWriter::PushQueque(const KinValues& kin)
	{
		std::lock_guard<std::mutex> lock(mtx);
		q.push (kin);
	}

	void ParentWriter::Run ()
	{
		while (cur_time <= end_time )
		{
			if (!q.empty())
			{
				KinValues kin_data = PopQueque();
				Sender(KinToString(kin_data));
				cur_time = kin_data.t;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		}
	}

	bool ParentWriter::Sender(const std::string& data_str) const
	{
		return true;
	}

	KinValues ParentWriter::PopQueque()
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