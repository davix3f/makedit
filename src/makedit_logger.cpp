#include "makedit_namespaces.h"

namespace makedit_logger
{
	int write_to_file = 0;
	
	void init()
	// Init without file logging
	{
		std::cout << "No argument provided. Setting write_to_file (" << &write_to_file << ") to FALSE" << std::endl;
		write_to_file = 1;
	}
	
	void init(bool filewrite)
	// If 'filewrite' is 2, all logging
	// will be also written on a file
	// If 'filewrite' is 1, no file logging
	{
		if (filewrite==true)
		{
			write_to_file = 2;
			std::cout << "Setting write_to_file (" << &write_to_file << ") to TRUE" << std::endl;
		}
		else
		{
			write_to_file = 1;
			std::cout << "Setting write_to_file (" << &write_to_file << ") to FALSE" << std::endl;
		}
	}

	bool log(Gtk::Object *sender, const char* message)
	// Logs a message from a specific
	// item, with its mem address
	{
		if (write_to_file==0)
		{
			std::cout << "Log value write_to_file (" << &write_to_file << ") is NULL. Log operations can't be performed" << std::endl;
			return false;
		}
		std::cout << message << " [Sender: " << sender << "]" << std::endl;
		return true;
	}
	
	bool log(const char* message)
	// Only text logging
	{
		if (write_to_file==0)
		{
			std::cout << "Log value write_to_file (" << &write_to_file << ") is NULL. Log operations can't be performed" << std::endl;
			return false;
		}
		std::cout << message << std::endl;
		return true;
	}
}
