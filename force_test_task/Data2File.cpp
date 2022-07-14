#include <iostream>
#include <fstream>
#include "Data2File.h"
#include "Data.h"

namespace dynamics
{
	bool Data2File::its_time_to_record(double time, double rec_interval, double dt)
	{
		return (abs(time / rec_interval - round(time / rec_interval)) < dt / 4);
	}


	void Data2File::add_line(const KinValues kin)
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
} 
