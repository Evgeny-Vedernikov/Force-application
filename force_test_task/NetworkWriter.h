#pragma once

#include "ParentWriter.h"

namespace dynamics
{
	class NetworkWriter : public ParentWriter
	{
	public:
		NetworkWriter(double end_time, const std::string& host, const int16_t port);
		~NetworkWriter() = default; 

		bool sender(const std::string& data_str) override;

	protected:


	private:
		std::string host_;
		int16_t port_;
	};
}