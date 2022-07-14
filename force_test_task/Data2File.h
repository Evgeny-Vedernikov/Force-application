#pragma once
#include "MatPoint.h"
namespace dynamics
{
	class Data2File
	{
	public:

		bool its_time_to_record(double time, double rec_interval, double dt);

		void add_line(const KinValues kin);

	private:

	};
}