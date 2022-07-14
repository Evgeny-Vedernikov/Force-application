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
		std::ofstream out;  // поток для записи
		out.open("record.txt", std::ios::app); // окрываем файл для записи
		if (out.is_open())  // TODO - чтобы папка создавалась при отсутствии
							// добавить дату-время в имя файла,
							// добавить шапку файла
		{
			//out.precision(6);
			//out << std::fixed;
			out  << "t = " << kin.t << "    V = " << kin.v << "    x = " << kin.x << std::endl;
			out.close();
		}
	}
} 
