#include "Includes.hpp"
	
//	Path
std::string defaultPath;
std::string selectedPath;


//	Mod
std::string selectedGroup;


int main() {
	load();

	std::cout << foreground::lightBlue << "v2.0.0" << foreground::reset << std::endl;
	std::cout << foreground::lightBlack << "Use 'help' to list available commands." << foreground::reset << std::endl;

	while (true) {
		std::string input;
		std::cout << indicator::input;
		std::getline(std::cin, input);
		process(input);
		std::cout << std::endl;
	}
}