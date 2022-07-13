#include "MatPoint.h"
namespace LibMatPoint
{
	mat_point::mat_point(double a_x, double dt) :a_dt(a_x* dt)
	{
	}
	void mat_point::iteration(double dt, mat_point::DynValues& dyn)
	{
		dyn.vel_x += a_dt;
		//output.coord_x = input.coord_x + ((input.Vel_x + output.Vel_x) / 2) * input.d_time;
		dyn.coord_x += dyn.vel_x * dt;
	}

	void mat_point::run(double time, double dt, double end_time, mat_point::DynValues& dyn)
	{
		while (time <= end_time)
		{
			time += dt;
			iteration (dt, dyn);
		}
	}
}
