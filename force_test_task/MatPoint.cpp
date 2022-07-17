#include <iostream>
#include <fstream>
#include <math.h>
#include "MatPoint.h"
#include "Data2File.h"
#include "Data.h"
namespace dynamics
{
	MatPoint::MatPoint(double a, double dt, double t0, double v0, double x0, Dispatcher& dispatcher, HandlerType handler)
		: dt_(dt), t0_(t0), v0_(v0), x0_(x0), a_dt_(a * dt), dispatcher_(dispatcher), handler_(handler)
	{
	}
	void MatPoint::iteration(KinValues& kin)
	{
		kin.v += a_dt_;
		kin.x += kin.v * dt_;
	}


	double MatPoint::TimeRun(double end_time, KinValues& kin) 
	{
		kin.t = t0_;
		kin.v = v0_;
		kin.x = x0_;

		handler_(dispatcher_, kin, true);

		while (kin.t <= end_time)
		{
			kin.t += dt_;
			iteration (kin);
			handler_(dispatcher_, kin, false);
			
			//if (data2file.its_time_to_record(kin.t, 0.1, dt_))
			//{
			//	data2file.add_line(kin);
			//};//сделать 0.1 одним из начальных параметров
		}
		return (kin.t);
	}
} 
