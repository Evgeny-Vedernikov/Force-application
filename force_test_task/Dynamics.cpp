#include "Dynamics.h"
namespace LibDynamics
{
	void Dynamics::iteration(const Dynamics::Input& input, Dynamics::Output& output)
	{
		double acceleration_x = input.Force_x / input.mass;
		output.Vel_x = input.Vel_x + acceleration_x * input.d_time;
		output.coord_x = input.coord_x + ((input.Vel_x + output.Vel_x) / 2) * input.d_time;
		output.time = input.time + input.d_time;



	}
}
