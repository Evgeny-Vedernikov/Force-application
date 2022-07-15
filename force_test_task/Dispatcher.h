#pragma once
#include "AbstractWriter.h"
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{
	class Dispatcher 
	{
	public:
		Dispatcher(const std::string& host, int16_t port, const std::string& file_name);
		~Dispatcher() = default;

			static void IterationHandler(Dispatcher& v, const KinValues& kin);

	protected:

	private:
		std::string host_;
		int16_t port_;
		std::string file_name_;
	};
}