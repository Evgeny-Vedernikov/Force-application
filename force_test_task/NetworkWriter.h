#pragma once
#include "AbstractWriter.h"
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{
	class NetworkWriter : public AbstractWriter
	{
	public:
		NetworkWriter(const std::string& host, const int16_t port);
		~NetworkWriter() = default; 

		bool UDPsender(const KinValues& kin);

	protected:


	private:
		std::string host_;
		int16_t port_;
	};
}