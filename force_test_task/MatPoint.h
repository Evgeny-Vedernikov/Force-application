#pragma once
namespace LibMatPoint
{
	class MatPoint
	{
	public:
		explicit MatPoint(double a, double dt, double t0, double v0, double x0);
		~MatPoint() = default;
		struct KinValues
		{
			double t;
			double v;
			double x;
		};

		void iteration(KinValues& kin);

		double time_run(double end_time, KinValues& kin);

	private:
		double dt_;
		double t0_;
		double v0_;
		double x0_;
		double a_dt_;
	};
}