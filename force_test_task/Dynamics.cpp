#include "Dynamics.h"
namespace Lib_Dyn_data
{
	mater_point::mater_point(double a_x, double d_time) :a_dt(a_x* d_time)
	{
	}
	void mater_point::iteration(double d_time, mater_point::DynData& dyn_data)
	{
		dyn_data.vel_x += a_dt;
		//output.coord_x = input.coord_x + ((input.Vel_x + output.Vel_x) / 2) * input.d_time;
		dyn_data.coord_x += dyn_data.vel_x * d_time;
	}

	void mater_point::run(double time, double d_time, double end_time, mater_point::DynData& dyn_data)
	{
		while (time <= end_time)
		{
			time += d_time;
			iteration (d_time, dyn_data);
		}
	}
}
