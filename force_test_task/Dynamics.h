#pragma once
namespace Lib_Dyn_data
{
	class mater_point
	{
	public:
		explicit mater_point()=default;
		~mater_point() = default;
		struct DynData
		{
			double coord_x;
			double vel_x;
			double accel_x;
		};
	
		void iteration(double d_time, DynData& dyn_data);

		void run(double time, double d_time, double end_time, DynData& dyn_data);

	private:

	};
}