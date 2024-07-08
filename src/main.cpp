#include <iostream>
#include <argh.h>
#include "process.cpp"

using namespace std;

int main(int argc, char** argv) {
	string outputFilePath, inputFilePath, includeDirPath;
	bool compileAndRun = false, compileAndRunNoSave = false;

	argh::parser parser(argv);	
	
	parser({"-o"}, "out") >> outputFilePath;
	parser({"-I"}, "./include/") >> includeDirPath;
	compileAndRun = (parser[{"-r"}]) ? true : false; 
	compileAndRunNoSave = (parser[{"-a"}]) ? true : false;
	
	if (compileAndRun && compileAndRunNoSave) {
		cerr << "Error: Flags -r and -a cannot be together" << endl;
		return 1;
	}

	if (parser.size() <= 1) {
		cerr << "Error: Missing arguments." << endl;
		return 1;
	} else if (parser.size() == 2) {
		inputFilePath = parser[1];
		if (compileAndRun) {
			if(build(inputFilePath, outputFilePath, includeDirPath) == 0) {
				run(outputFilePath);
			}
		} else if (compileAndRunNoSave) {
			if (build(inputFilePath, outputFilePath, includeDirPath) == 0) {
				if (run(outputFilePath) == 0) {
					clean(outputFilePath);
				}
			}
		} else {
			build(inputFilePath, outputFilePath, includeDirPath);
		}

	} else {
		cerr << "Error: Too many arguments." << endl;
		return 1;
	}

	return 0;	
}
