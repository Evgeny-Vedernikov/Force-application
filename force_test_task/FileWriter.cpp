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
		std::ofstream out;  // поток для записи
		out.open("file_name", std::ios::app); // окрываем файл для записи
		if (out.is_open())  // TODO - чтобы папка создавалась при отсутствии
							// добавить дату-время в имя файла,
							// добавить шапку файла
		{
			//out.precision(6);
			//out << std::fixed;
			out << "t = " << kin.t << "    V = " << kin.v << "    x = " << kin.x << std::endl;
			out.close();
		}

	//IterationHandler(const KinValues& kin);


} 

