#include "makedit_namespaces.h"

namespace makedit_fileops
{
	// Check user r/w permission on a file
	int file_write_permission_checker(const char* file_name)
	{
		std::fstream file;
		file.open(file_name, std::ios::app);
		if(file.is_open())
		{
			std::cout << "File \'" << file_name << "\' can be opened in READ-WRITE mode" << std::endl;
			file.close();
			return(true);
		}
		else
		{
			std::cout << "File \'" << file_name << "\' can be opened in READ-ONLY mode, or doesn't exist" << std::endl;
			return(false);
		}
	}
}
