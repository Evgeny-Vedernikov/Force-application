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
		FileWriter(const std::string& file_name);
		~FileWriter() = default;

		//static void IterationHandler(const FileWriter& v, const KinValues& kin);
		void add_line(const KinValues kin) const;

	protected:


	private:
		std::string file_name_;
	};
}