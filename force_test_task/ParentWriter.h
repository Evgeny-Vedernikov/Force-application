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
		static std::string kin_to_string(const KinValues& kin);

		ParentWriter(double a_end_time);
		void push_queue(const KinValues& kin);
		KinValues pop_queue();
		virtual bool sender(const std::string& data_str) = 0;
		void run();

	protected:
		using QueueType = std::queue < KinValues, std::deque<KinValues> >;
		double end_time;
		double cur_time;
		QueueType q;
		std::mutex mtx;
	};
}