#include <iostream>
#include <fstream>
#include "Data2File.h"

namespace dynamics
{
	bool Data2File::its_time_to_record(double time, double rec_interval, double dt)
	{
		return (abs(time / rec_interval - round(time / rec_interval)) < dt / 4);
	}


	void Data2File::add_line(const MatPoint::KinValues kin)
	{	
		std::ofstream out;  // ����� ��� ������
		out.open("record.txt", std::ios::app); // �������� ���� ��� ������
		if (out.is_open())  // TODO - ����� ����� ����������� ��� ����������
							// �������� ����-����� � ��� �����,
							// �������� ����� �����
		{
			//out.precision(6);
			//out << std::fixed;
			out  << "t = " << kin.t << "    V = " << kin.v << "    x = " << kin.x << std::endl;
			out.close();
		}
	}
			//LibData2File::Data2File::data dat;
			//dat.time = time;
			//dat.vel_x = kin.vel_x;
			//dat.coord_x = kin.coord_x;

			//LibData2File::Data2File data_2_file;
			//data_2_file.add_line(dat);
} 
