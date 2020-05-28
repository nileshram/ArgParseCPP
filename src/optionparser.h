/*
 * parser.h
 *
 *  Created on: 27 May 2020
 *      Author: Nilesh
 */

#ifndef OPTIONPARSER_H_
#define OPTIONPARSER_H_

#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

using std::cout;
using std::endl;

class OptionParser
{
public:
	OptionParser();
	void init_desc();
	int parse_cmd_line(int _argc, char **_argv);
	std::string get_filein_path();
	std::string get_vm_filein_path();
private:
	po::options_description _desc;
	po::variables_map _vm;
	std::string _filein_path;

};



#endif /* OPTIONPARSER_H_ */
