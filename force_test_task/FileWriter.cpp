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

	bool FileWriter::Sender(const std::string& data_str) const

	{
		std::ofstream out;  // поток для записи
		out.open(file_name_, std::ios::app); // окрываем файл для записи
		bool result = out.is_open();
		if (result)  
		{
			out << data_str.c_str();
			out.close();
		}
		return result;
	}
} 

