#pragma once

std::map<std::string, std::vector<std::string>> listGroups;
std::map<unsigned int, std::string> listPaths;

namespace command{
	const std::string path = "path";
	const std::string mod = "mod";
	const std::string help = "help";
	const std::string clear = "clear";
};


std::string option(std::string string) {
	std::string result;
	result += indicator::option;
	for (int position = 0; position < string.size(); ++position) {
		if (position < 1) {
			result += style::bold + "[" + foreground::darkBlue + string[position] + style::reset + "]";
		}
		else {
			result += string[position];
		}
	}
	return result;
}

void clear() {
	system("cls");
}


void load() {
	nlohmann::json settings;
	std::ifstream file(getPath(FOLDERID_RoamingAppData));
}


void unload() {

}


void path() {
	
}


void mod() {
	std::cout << option("Group") << std::endl;
	std::cout << option("Individual") << std::endl;
	std::cout << option("Quit") << std::endl;

	std::string action;
	std::string name;
	
	while (true) {
		if (action != "Q") {
			std::cout << indicator::input;
			std::getline(std::cin, action);
			std::transform(action.begin(), action.end(), action.begin(), std::toupper);

			//	[G]roup
			if (action == "G") {
				action.clear();
				std::cout << option("Add") << std::endl;
				std::cout << option("Remove") << std::endl;
				std::cout << option("Edit") << std::endl;
				std::cout << option("List") << std::endl;
				std::cout << option("Quit") << std::endl;

				while (true) {
					std::cout << indicator::input;
					std::getline(std::cin, action);
					std::transform(action.begin(), action.end(), action.begin(), std::toupper);

					//	[Q]uit
					if (action == "Q") {
						action.clear();
						return;
					}

					//	[A]dd
					if (action == "A") {
						action.clear();
						while (true) {
							std::cout << indicator::input;
							std::getline(std::cin, action);
							if (action != "Q") {
								listGroups[action];
							}
							else {
								action.clear();
								break;
							}
						}
					}

					//	[R]emove
					if (action == "R") {
						action.clear();
						std::cout << indicator::input;
						std::getline(std::cin, action);
						listGroups.erase(action);
					}

					//	[E]dit
					if (action == "E") {
						action.clear();
						std::cout << indicator::input;
						std::getline(std::cin, name);

						std::cout << option("Add") << std::endl;
						std::cout << option("Remove") << std::endl;
						std::cout << option("Quit") << std::endl;

						std::cout << indicator::input;
						std::getline(std::cin, action);
						std::transform(action.begin(), action.end(), action.begin(), std::toupper);

						while (true) {
							//	[Q]uit
							if (action == "Q") {
								action.clear();
								name.clear();
								break;
							}

							//	[A]dd
							if (action == "A") {
								action.clear();
								while (true) {
									std::cout << indicator::input;
									std::getline(std::cin, name);
									if (action != "Q") {
										listGroups[name].push_back(action);
									}
									else {
										action.clear();
										name.clear();
										break;
									}
								}
								break;
							}

							//	[R]emove
							if (action == "R") {
								action.clear();
								while (true) {
									std::cout << indicator::input;
									std::getline(std::cin, name);
									if (action != "Q") {
										listGroups[name].erase(std::remove(listGroups[action].begin(), listGroups[action].end(), action), listGroups[action].end());
									}
									else {
										action.clear();
										name.clear();
										break;
									}
								}
								break;
							}

							//	404
							if (action.find_first_not_of("ARQ") != std::string::npos) {
								action.clear();
								std::cout << foreground::lightRed << "Command not found." << style::reset << std::endl;
								break;
							}
						}
					}

					//	[L]ist
					if (action == "L") {
						action.clear();
						std::cout << option("Groups") << std::endl;
						std::cout << option("Mods") << std::endl;
						std::cout << option("Quit") << std::endl;

						std::cout << indicator::input;
						std::getline(std::cin, action);
						std::transform(action.begin(), action.end(), action.begin(), std::toupper);

						while (true) {
							//	[Q]uit
							if (action == "Q") {
								action.clear();
								break;
							}

							//	[G]roups
							if (action == "G") {
								action.clear();
								for (auto& element : listGroups) {
									std::cout << indicator::option << foreground::lightBlack << element.first << style::reset << std::endl;
								}
								break;
							}

							//	[M]ods
							if (action == "M") {
								action.clear();
								std::cout << indicator::input;
								std::getline(std::cin, name);
								for (auto& element : listGroups[name]) {
									std::cout << indicator::option << foreground::lightBlack << element << style::reset << std::endl;
								}
								name.clear();
								break;
							}

							//	404
							if (action.find_first_not_of("QGM") != std::string::npos) {
								action.clear();
								std::cout << foreground::lightRed << "Command not found." << style::reset << std::endl;
								break;
							}
						}
					}

					//	404
					if (action.find_first_not_of("QAREL") != std::string::npos) {
						std::cout << foreground::lightRed << "Command not found." << style::reset << std::endl;
					}
				}
				std::cout << std::endl;
			}

			//	[I]ndividual
			if (action == "I") {
				return;
			}

			//	404
			if (action.find_first_not_of("GIQ") != std::string::npos) {
				std::cout << foreground::lightRed << "Option not found." << foreground::reset << std::endl;
			}
		}
		else {
			action.clear();
			break;
		}
	}
}

void help() {
	
}


void process(std::string input) {
	//	Path
	if (input == command::path) {
		return path();
	}

	//	Mod
	if (input == command::mod) {
		return mod();
	}

	//	Help
	if (input == command::help) {
		return help();
	}

	//	Clear
	if (input == command::clear) {
		return clear();
	}

	//	404
	std::cout << foreground::lightRed << "Command not found." << foreground::reset << std::endl;
	return;
}
