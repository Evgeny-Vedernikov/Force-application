#include <iostream>
#include <fstream>
#include <math.h>
#include "MatPoint.h"
#include "Data2File.h"
#include "Data.h"
namespace dynamics
{
	MatPoint::MatPoint(double a, double dt, const KinValues& kin)
		: dt_(dt), a_dt_(a * dt), kin0(kin), dispatcher_(nullptr), handler_(nullptr)
	{
	}
	void MatPoint::iteration(KinValues& kin)
	{
		kin.v += a_dt_;
		kin.x += kin.v * dt_;
	}

	void MatPoint::Init(Dispatcher& dispatcher, HandlerType handler)
	{
		dispatcher_ = &dispatcher;
		handler_ = handler;
	}

	void  MatPoint::TimeRun(double end_time, KinValues& kin) 
	{
		kin = kin0;

		handler_(*dispatcher_, kin, true);

		while (kin.t <= end_time)
		{
			kin.t += dt_;
			iteration (kin);
			handler_(*dispatcher_, kin, false);
		}
	}
} 
