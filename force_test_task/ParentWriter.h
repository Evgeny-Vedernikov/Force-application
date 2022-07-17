#pragma once
#include "Data.h"
#include <queue>
#include <string>

namespace dynamics
{
	class ParentWriter
	{
	public:
		ParentWriter() : t(0), q()
		{
		};
		static std::string kin_to_string(const KinValues& kin);

	protected:
		double t; ///
		std::queue < KinValues, std::deque<KinValues> > q;
		
	};
}