#pragma once
namespace LibDynamics
{

	class Dynamics
	{
	public:
		explicit Dynamics();
		~Dynamics() = default;
		struct Input
		{
			double coord_x;
			double Vel_x;
			double Force_x;
			double mass;
			double time;
			double d_time;
		};
	
		struct Output
		{
			double coord_x;
			double Vel_x;
			double time;
		};
		void iteration(const Input& input, Output& output);

	private:

	};
}