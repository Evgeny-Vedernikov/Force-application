#include "FileWriter.h"
#include <iostream>
#include <fstream>

namespace dynamics
{
	FileWriter::FileWriter(double end_time, const std::string& file_name)
		: ParentWriter(end_time)
		, file_name_(file_name)
	{
	}

	bool FileWriter::Sender(const std::string& data_str)
	{
		std::ofstream out;
		out.open(file_name_, std::ios::app);
		bool result = out.is_open();
		if (result)  
		{
			out << data_str.c_str();
			out.close();
		}
		return result;
	}
} 

