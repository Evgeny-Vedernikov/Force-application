#pragma once

#include "ParentWriter.h"

namespace dynamics
{
	class FileWriter : public ParentWriter
	{
	public:
		FileWriter(double end_time, const std::string& file_name);
		~FileWriter() = default;

		bool Sender(const std::string& data_str) override;

	private:
		std::string file_name_;
	};
}