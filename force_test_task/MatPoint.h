#pragma once
#include "Data.h"
#include "Dispatcher.h"


namespace dynamics
{

	class MatPoint
	{
	public:
		explicit MatPoint(double a, double dt, double t0, double v0, double x0, Dispatcher& dispatcher, HandlerType handler);
		~MatPoint() = default;

		void iteration(KinValues& kin);

		double time_run(double end_time, KinValues& kin);

	private:
		double dt_;
		double t0_;
		double v0_;
		double x0_;
		double a_dt_;
		Dispatcher& dispatcher_;
		HandlerType handler_;
	};
}