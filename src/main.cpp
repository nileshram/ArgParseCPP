//============================================================================
// Name        : ProgramParserCPP.cpp
// Author      : Nilesh Ramnarain
// Version     :
// Copyright   : Your copyright notice
// Description : Boost wrapper for argparser -l boost_program_options
//============================================================================

#include <iostream>
using namespace std;

#include "optionparser.h"

int main(int argc, char **argv)
{
	OptionParser argparse;
	if (argparse.parse_cmd_line(argc, argv) == 0)
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}


	//test
	cout << argparse.get_filein_path() << endl;
	cout << argparse.get_vm_filein_path() << endl;

	return 0;
}
