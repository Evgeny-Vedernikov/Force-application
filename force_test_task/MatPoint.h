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
	
		void iteration(KinValues& kin);

		double time_run(double time, double end_time, KinValues& kin);

	private:
		double dt_;
		double a_dt_;
		
	};
}