#pragma once
#include "AbstractWriter.h"
#include "Data.h"
#include <queue>
#include <string>
namespace dynamics
{
	class FileWriter : public AbstractWriter
	{
	public:
		FileWriter(const std::string& file_name);
		~FileWriter() = default;

		static void IterationHandler(const FileWriter& v, const KinValues& kin);
		void add_line(const KinValues kin) const;

	protected:


	private:
		std::string file_name_;
	};
}