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
		static std::string KinToString(const KinValues& kin);

		ParentWriter(double a_end_time);
		void PushQueque(const KinValues& kin);
		KinValues PopQueque();
		virtual bool Sender(const std::string& data_str) = 0;
		void Run();

	protected:
		using QueueType = std::queue < KinValues, std::deque<KinValues> >;
		double end_time;
		double cur_time;
		QueueType q;
		std::mutex mtx;
	};
}