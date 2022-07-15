#pragma once
#include <functional>

namespace dynamics
{
	struct KinValues
	{
		double t;
		double v;
		double x;
	};
	class Dispatcher;

	using HandlerType = std::function<void(Dispatcher&, const KinValues&)>;
}