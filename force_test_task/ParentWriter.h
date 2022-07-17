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

	protected:
		using QueueType = std::queue < KinValues, std::deque<KinValues> >;
		
		double end_time;
		double t;
		QueueType q;
		std::mutex mtx;
	};
}