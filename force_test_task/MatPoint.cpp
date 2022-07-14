#include <iostream>
#include <fstream>
#include <math.h>
#include "MatPoint.h"
#include "Data2File.h"
namespace LibMatPoint
{
	MatPoint::MatPoint(double a_x, double dt) :a_dt(a_x* dt)
	{
	}
	void MatPoint::iteration(double dt, MatPoint::KinValues& kin)
	{
		//vel_x_before = kin.vel_x
		kin.vel_x += a_dt;
		//kin.coord_x += ((kin.Vel_x + vel_x_before) / 2) * dt;
		kin.coord_x += kin.vel_x * dt;
	}

	void data_to_file(double time, double dt, double f_interval, MatPoint::KinValues& kin)
	{
		if ((time / f_interval - int(time / f_interval)) * f_interval < dt / 8)
		{	
			LibData2File::Data2File::data dat;
			dat.time = time;
			dat.vel_x = kin.vel_x;
			dat.coord_x = kin.coord_x;

			// std::cout << dat.time << "   " << dat.vel_x << "   " << dat.coord_x << std::endl;

			
			LibData2File::Data2File::add_line(dat);  // wtf?
			
			//std::ofstream out;          // поток для записи
			//out.open("records//record.txt", std::ios::app); // окрываем файл для записи
			//if (out.is_open())  // todo - как сделать, чтобы папка создавалась при отсутствии
			//{
			//	out << "t = " << time
			//		<< " ,    x = " << kin.coord_x
			//		<< " ,    v = " << kin.vel_x << std::endl;
			//	out.close();
			//}
		}
	}


	double MatPoint::time_run(double time, double dt, double end_time, MatPoint::KinValues& kin)
	{
		while (time <= end_time)
		{
			time += dt;
			iteration (dt, kin);
			data_to_file(time, dt, 0.1, kin);//сделать 0.1 одним из начальных параметров
		}
		return (time);
	}
} 
