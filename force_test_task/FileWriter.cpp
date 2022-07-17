#include <iostream>
#include <fstream>
#include "FileWriter.h"

namespace dynamics
{
	FileWriter::FileWriter(const std::string& file_name) : file_name_(file_name) 
	{
	}

	void FileWriter::add_line(const KinValues kin) const

	{
		std::ofstream out;  // ����� ��� ������
		out.open(file_name_, std::ios::app); // �������� ���� ��� ������
		if (out.is_open())  
		{
			out << kin_to_string(kin).c_str();
			out.close();
		}
	}
} 

