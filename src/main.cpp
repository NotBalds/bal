#include <iostream>
#include <vector>
#include <unistd.h>
#include <argh.h>

#define build "build"
#define run "run"
#define clear "clear"

using namespace std;

string InFileName, OutFileName;

void build_command(string InFileName, string OutFileName) {
	string command;

	cout << "[.] Building executable file..." << endl;;

	command = "g++ -I./include/ " + InFileName + " -o " + OutFileName;
	system(command.c_str());
		
	command = "chmod +x ./" + OutFileName;
	system(command.c_str());

	cout << "[+] Executable file compiled suuccesfully!" << endl;

}

void run_command(string OutFileName) {
	string command;

	cout << "Running '" + OutFileName + "'..." << endl;
	cout << "|---------- Start of the program ----------|" << endl;

	command = "./" + OutFileName;
	system(command.c_str());

	cout << "|---------- End of the program ----------|" << endl;
}

void clear_command(string OutFileName) {
	string command;

	cout << "[.] Clearing space..." << endl;
		
	command = "rm -rf ./" + OutFileName;
	system(command.c_str());

	cout << "[+] Space cleaned!" << endl;
}

int main(int argc, char** argv) {
	
	cout << "          _____             _         _ " << endl;
	usleep(9000);
	cout << "         |  _  |           | |       | |" << endl;
	usleep(9000);
	cout << "         | |_| |_   _____  | |  _____| |" << endl;
	usleep(9000);
	cout << "         |  __   | /  _  | | | /  __   |" << endl;
	usleep(9000);
	cout << "         | |__|  | | |_| | | | | |__|  |" << endl;
	usleep(9000);
	cout << "         |_______| \\__/|_| \\_\\ \\____/|_|" << endl;
	usleep(9000);
	cout << endl;
	usleep(9000);
	cout << "             ________________________   " << endl;
	usleep(9000);
	cout << "            |                        |  " << endl;
	usleep(9000);
	cout << "            |      Lite edition      |  " << endl;
	usleep(9000);
	cout << "            |        ( bal )         |  " << endl;
	usleep(9000);
	cout << "            |________________________|  " << endl;
	usleep(9000);
	cout << endl;
	usleep(9000);
	cout << "     [?] CPP building system based on g++ [?]" << endl;
	usleep(9000);
	cout << endl;

	vector<int> tasks;
	string param;
	
	
	argh::parser parser(argv);	
	
	parser({"-n", "--name"}, "out") >> OutFileName;
	parser({"-f", "--file"}, "./main.cpp") >> InFileName;

	string command;

	if (parser[1] == build)
	{
		build_command(InFileName, OutFileName);
	}
	else if (parser[1] == run)
	{
		run_command(InFileName);
	}
	else if (parser[1] == clear)
	{
		clear_command(InFileName);
	}
	else
	{
		if (parser.size() > 1)
		{
			cout << "[!] Incorrect call. Useful: bal <none|build|run|clear> [-n|--name=<name>|-f|--file=<file_to_compile>]" << endl;
		}
		else  
		{
			build_command(InFileName, OutFileName);
			run_command(OutFileName);
			clear_command(OutFileName);
		}
	}

	return 0;	
}
