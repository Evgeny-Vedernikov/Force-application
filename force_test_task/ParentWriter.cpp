#include "ParentWriter.h"
#include <iomanip>
#include <sstream>

namespace dynamics
{
	std::string ParentWriter::kin_to_string(const KinValues& kin) 
	{
		std::stringstream s;  // поток для записи
		std::int8_t prec = 14;

		s << std::fixed << std::setprecision(prec) << "t = " 
			<< std::setw(prec+3) << kin.t << "    V = " 
			<< std::setw(prec+4) << kin.v << "    x = "
			<< std::setw(prec+5) << kin.x << std::endl;
		return s.str();
	}
}