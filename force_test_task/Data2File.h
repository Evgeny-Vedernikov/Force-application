#pragma once
#include "MatPoint.h"
namespace LibData2File
{
	class Data2File
	{
	public:
		//Data2File() = default;
		//~Data2File() = default;
		//struct data
		//{	
		//	double time;
		//	double vel_x;
		//	double coord_x;
		//};

		bool its_time_to_record(double time, double rec_interval, double dt);

		void add_line(const LibMatPoint::MatPoint::KinValues kin, const double time);

	private:

	};
}