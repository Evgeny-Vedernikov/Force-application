#include "FileWriter.h"
namespace dynamics
{
	FileWriter::FileWriter(const std::string& file_name) : file_name_(file_name) 
	{
	}

	void FileWriter::IterationHandler(const FileWriter& v, const KinValues& kin)
	{
		v.add_line(kin);
	}

	void FileWriter::add_line(const KinValues kin)
	{
		std::ofstream out;  // ����� ��� ������
		out.open("file_name", std::ios::app); // �������� ���� ��� ������
		if (out.is_open())  // TODO - ����� ����� ����������� ��� ����������
							// �������� ����-����� � ��� �����,
							// �������� ����� �����
		{
			//out.precision(6);
			//out << std::fixed;
			out << "t = " << kin.t << "    V = " << kin.v << "    x = " << kin.x << std::endl;
			out.close();
		}

	//IterationHandler(const KinValues& kin);


} 

