#pragma once
#include "Data.h"
#include <queue>
namespace dynamics
{
	class AbstractWriter
	{
	public:

	protected:
		double t;
		std::queue < KinValues, std::deque<KinValues> > q;
		
	};
}