#pragma once
#include <functional>

namespace dynamics
{
	class FileWriter;
	class KinValues;

	using HandlerType = std::function<void (const FileWriter& , const KinValues& )> ;
	struct KinValues
	{
		double t;
		double v;
		double x;
	};
}