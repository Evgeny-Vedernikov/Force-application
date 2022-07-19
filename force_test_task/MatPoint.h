#pragma once

#include "Data.h"
#include "Dispatcher.h"

namespace dynamics
{
	class MatPoint
	{
	public:
		explicit MatPoint(double a, double dt, const KinValues& kin);
		~MatPoint() = default;

		void init_callback_data(Dispatcher& dispatcher, HandlerType handler);

		void iteration(KinValues& kin);

		void time_run(double end_time, KinValues& kin);

	private:
		double dt_;
		double a_dt_;
		KinValues kin0;
		Dispatcher* dispatcher_;
		HandlerType handler_;
	};
}