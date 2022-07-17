#pragma once
#include "ParentWriter.h"
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{
	class FileWriter : public ParentWriter
	{
	public:
		FileWriter(double end_time, const std::string& file_name);
		~FileWriter() = default;

		void add_line(const KinValues kin) const;

	private:
		std::string file_name_;
	};
}