#pragma once
#include "Data.h"
#include <queue>
namespace dynamics
{
	class AbstractWriter
	{
	public:
		//should_wr
		//static void IterationHandler(const KinValues& kin);

		



	protected:
		double t;
		std::queue < KinValues, std::deque<KinValues> > q;
		
	};
}