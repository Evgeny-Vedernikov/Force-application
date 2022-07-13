#pragma once
namespace Lib_Dyn_data
{
	class mater_point
	{
	public:
		explicit mater_point(double a_x, double d_time );
		~mater_point() = default;
		struct DynData
		{
			double coord_x;
			double vel_x;
		};
	
		void iteration(double d_time, DynData& dyn_data);

		void run(double time, double d_time, double end_time, DynData& dyn_data);

	private:
		double a_dt;
	};
}