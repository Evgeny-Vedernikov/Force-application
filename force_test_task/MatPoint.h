#pragma once
namespace LibMatPoint
{
	class mat_point
	{
	public:
		explicit mat_point(double a_x, double dt ); // explicit ?
		~mat_point() = default;
		struct DynValues
		{
			double coord_x;
			double vel_x;
		};
	
		void iteration(double dt, DynValues& dyn);

		void run(double time, double dt, double end_time, DynValues& dyn);

	private:
		double a_dt;
	};
}