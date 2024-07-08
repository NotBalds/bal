#include <iostream>

using namespace std;

void log(string object, int status) {
	if (status == 0) {
		cout << "[+] " << object << ": successful" << endl;
	} else if (status == 1) {
		cout << "[-] " << object << ": failure" << endl;
	} else if (status == 2) {
		cout << "[.] " << object << ": in process" << endl;
	} else if (status == 3) {
		cout << "[?] " << object << endl;
	}
}

int build(string inputFilePath, string outputFilePath, string includeDirPath) {
	string command = "g++ -o " + outputFilePath + " -I " + includeDirPath + " " + inputFilePath + " > /dev/null";
	int status = system(command.c_str());
	
	log("Building", 2);

	if (status == 0) {
		log("Building", 0);
	} else {
		log("Building", 1);
		if (status == 256) {
			log("File not found", 3);
		}
		return 1;
	}

	return 0;
}

int run(string inputFilePath) {
	if (!(inputFilePath.substr(0, 1) == "/" || inputFilePath.substr(0, 1) == "~")) {
		inputFilePath = "./" + inputFilePath;
	}

	string command = "chmod +x " + inputFilePath + " > /dev/null";
	int status = system(command.c_str());
	
	log("Giving permissions", 2);

	if (status == 0) {
		log("Giving permissions", 0);
	} else {
		log("Giving permissions", 1);
		return 1;
	}

	command = inputFilePath;
	
	log("Running", 2);

	status = system(command.c_str());

	if (status == 0) {
		log("Running", 0);
	} else {
		log("Running", 1);
		return 1;
	}

	return 0;
}

int clean(string outputFilePath) {
	
	if (!(outputFilePath.substr(0, 1) == "/" || outputFilePath.substr(0, 1) == "~")) {
		outputFilePath = "./" + outputFilePath;
	}
	
	string command = "rm " + outputFilePath + " > /dev/null";	
	
	log("Cleaning", 2);

	int status = system(command.c_str());

	if (status == 0) {
		log("Cleaning", 0);
	} else {
		log("Cleaning", 1);
		return 1;
	}

	return 0;
}
