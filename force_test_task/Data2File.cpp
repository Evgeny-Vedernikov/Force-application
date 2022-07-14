#include <iostream>
#include <fstream>
#include "Data2File.h"

namespace LibData2File
{
	void Data2File::add_line(Data2File::data& dat)
	{	
		std::ofstream out;          // ����� ��� ������
		out.open("records//record.txt", std::ios::app); // �������� ���� ��� ������
		if (out.is_open())  // TODO - ��� �������, ����� ����� ����������� ��� ����������
		{
			out << "t = " << dat.time
			<< " ,    V = " << dat.vel_x
			<< " ,    x = " << dat.time << std::endl;
			out.close();
		}
		//if ((time / f_interval - int(time / f_interval)) * f_interval < dt / 8) {}
	}
} 
