/*
 * parser.cpp
 *
 *  Created on: 27 May 2020
 *      Author: Nilesh
 */

#include "optionparser.h"

OptionParser::OptionParser() : _desc("Allowed program options")
{
	init_desc();
}

void OptionParser::init_desc()
{
	_desc.add_options()
			("help,h", "Produce help message")
			("version,v", "Display version number")
			("input_files,I", po::value<std::string>(&_filein_path)->default_value("file/"), "Path to input files");
}

int OptionParser::parse_cmd_line(int _argc, char **_argv)
{
	//note that the following three lines are required to parse the command line
	//and store the variables inside of the variable maps container
	po::store(po::parse_command_line(_argc, _argv, _desc), _vm);
	po::notify(_vm);

	if (_vm.count("help"))
	{
		cout << _desc << endl;
		return -1;
	}

	if (_vm.count("version"))
	{
		cout << "Version number 1.0.0" << endl;
		return -1;
	}

	return 0;
}

std::string OptionParser::get_filein_path()
{
	return _filein_path;
}

std::string OptionParser::get_vm_filein_path()
{
	return _vm["input_files"].as<std::string>();
}
