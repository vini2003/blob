#pragma once


namespace indicator {
	const std::string option = "> ";
	const std::string input = ": ";
}


//	ASCII-only
std::wstring to_wstring(std::string str) {
	return std::wstring(str.begin(), str.end());
}


//	ASCII-only
std::string to_string(std::wstring wstr) {
	for (char chr : wstr) {
		if (chr < 0 || chr > 127) {
			std::cout << foreground::lightRed << "Input must be within ASCII standard." << foreground::reset << std::endl;
			return NULL;
		}
	}
	return std::string(wstr.begin(), wstr.end());
}


//	ASCII-only
std::string getPath(GUID FolderID) {
	wchar_t* savePath;
	SHGetKnownFolderPath(FolderID, 0, NULL, &savePath);
	return to_string(savePath);
}