#pragma once
namespace LibData2File
{
	class Data2File
	{
	public:
		Data2File() = default;
		~Data2File() = default;
		struct data
		{	
			double time;
			double vel_x;
			double coord_x;
		};

		void add_line(Data2File::data& dat);

	private:

	};
}