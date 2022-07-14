#pragma once
#include "AbstractWriter.h"
#include "Data.h"
#include <queue>
namespace dynamics
{
	class FileWriter : public AbstractWriter
	{
	public:
		FileWriter(const std::string& file_name);
		~FileWriter() = default;

		static void IterationHandler(const FileWriter& v, const KinValues& kin);

	protected:
		void FileWriter::add_line(const KinValues kin)


	private:
		std::string file_name_;
		

		
	};
}