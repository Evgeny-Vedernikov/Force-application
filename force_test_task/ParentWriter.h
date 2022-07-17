#pragma once
#include "Data.h"
#include <queue>
#include <string>
#include <mutex>

namespace dynamics
{
	class ParentWriter
	{
	public:
		ParentWriter(double a_end_time);
		static std::string KinToString(const KinValues& kin);
		void PushQueque(const KinValues& kin);
		KinValues PopQueque();
		virtual bool Sender(const std::string& data_str) const;
		void Run();

	protected:

		using QueueType = std::queue < KinValues, std::deque<KinValues> >;
		
		double end_time;
		QueueType q;
		std::mutex mtx;
		double cur_time;
	};
}