#include <iostream>
#include <fstream>
#include <math.h>
#include "MatPoint.h"
namespace LibMatPoint
{
	MatPoint::MatPoint(double a_x, double dt) :a_dt(a_x* dt)
	{
	}
	void MatPoint::iteration(double dt, MatPoint::KinValues& kin)
	{
		kin.vel_x += a_dt;
		//output.coord_x = input.coord_x + ((input.Vel_x + output.Vel_x) / 2) * input.d_time;
		kin.coord_x += kin.vel_x * dt;
	}

	void data_to_file(double time, double dt, double f_interval, MatPoint::KinValues& kin)
	{
		if ((time / f_interval - int(time / f_interval)) * f_interval < dt / 8)
		{
			std::ofstream out;          // поток для записи
			out.open("record.txt"); // окрываем файл для записи
			if (out.is_open())
			{
				out << "t = " << time
					<< " ,    x = " << kin.coord_x
					<< " ,    V = " << kin.vel_x << std::endl;
			}
			std::cout << "t = ," << time
				<< ",    x = ," << kin.coord_x 
				<< ",    V = ," << kin.vel_x << std::endl;
		}
	}


	double MatPoint::time_run(double time, double dt, double end_time, MatPoint::KinValues& kin)
	{
		
		while (time <= end_time)
		{
			time += dt;
			iteration (dt, kin);
			data_to_file(time, dt, 0.1, kin);
			
		}
		return (time);
	}
} 
