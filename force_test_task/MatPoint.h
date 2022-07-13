#pragma once
namespace LibMatPoint
{
	class MatPoint
	{
	public:
		explicit MatPoint(double a_x, double dt ); // explicit ?
		~MatPoint() = default;
		struct KinValues
		{
			double coord_x;
			double vel_x;
		};
	
		void iteration(double dt, KinValues& kin);

		void run(double time, double dt, double end_time, KinValues& kin);

	private:
		double a_dt;
	};
}