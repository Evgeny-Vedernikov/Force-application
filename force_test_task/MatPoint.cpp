#include <iostream>
#include <fstream>
#include <math.h>
#include "MatPoint.h"
#include "Data2File.h"
namespace LibMatPoint
{
	MatPoint::MatPoint(double a_x, double dt) : dt_(dt), a_dt_(a_x* dt)
	{
	}
	void MatPoint::iteration(MatPoint::KinValues& kin)
	{
		//vel_x_before = kin.vel_x
		kin.vel_x += a_dt_;
		kin.coord_x += kin.vel_x * dt_;
	}


	double MatPoint::time_run(double time, double end_time, MatPoint::KinValues& kin)
	{
		LibData2File::Data2File data2file; // где его создать лучше?
		while (time <= end_time)
		{
			time += dt_;
			iteration (kin);

			if (data2file.its_time_to_record(time, 0.1, dt_))
			{
				data2file.add_line(kin, time);
			};//сделать 0.1 одним из начальных параметров
		}
		return (time);
	}
} 
