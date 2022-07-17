#include <iostream>
#include <fstream>
#include "FileWriter.h"

namespace dynamics
{
	FileWriter::FileWriter(double end_time, const std::string& file_name)
		: ParentWriter(end_time)
		, file_name_(file_name)
	{
	}

	void FileWriter::add_line(const KinValues kin) const

	{
		std::ofstream out;  // ����� ��� ������
		out.open(file_name_, std::ios::app); // �������� ���� ��� ������
		if (out.is_open())  
		{
			out << KinToString(kin).c_str();
			out.close();
		}
	}
} 

