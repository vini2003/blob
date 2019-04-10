#pragma once

namespace style {
	//	Style
	const std::string bold = "\033[1m";
	const std::string faint = "\033[2m";
	const std::string italic = "\033[3m";
	const std::string underline = "\033[4m";
	const std::string slowBlink = "\033[5m";
	const std::string fastBlink = "\033[6m";
	const std::string inverse = "\033[7m";
	const std::string conceal = "\033[8m";

	//	Other
	const std::string reset = "\033[0m";
}

namespace foreground {
	//	Dark
	const std::string darkBlack = "\033[30m";
	const std::string darkRed = "\033[31m";
	const std::string darkGreen = "\033[32m";
	const std::string darkYellow = "\033[33m";
	const std::string darkBlue = "\033[34m";
	const std::string darkMagenta = "\033[35m";
	const std::string darkCyan = "\033[36m";
	const std::string darkWhite = "\033[37m";

	//	Bright
	const std::string lightBlack = "\033[90m";
	const std::string lightRed = "\033[91m";
	const std::string lightGreen = "\033[92m";
	const std::string lightYellow = "\033[93m";
	const std::string lightBlue = "\033[94m";
	const std::string lightMagenta = "\033[95m";
	const std::string lightCyan = "\033[96m";
	const std::string lightWhite = "\033[97m";

	// Other
	const std::string reset = "\033[39m";
};

namespace background {
	//	Dark
	const std::string darkBlack = "\033[40m";
	const std::string darkRed = "\033[41m";
	const std::string darkGreen = "\033[42m";
	const std::string darkYellow = "\033[43m";
	const std::string darkBlue = "\033[44m";
	const std::string darkMagenta = "\033[45m";
	const std::string darkCyan = "\033[46m";
	const std::string darkWhite = "\033[47m";

	//	Bright
	const std::string lightBlack = "\033[100m";
	const std::string lightRed = "\033[101m";
	const std::string lightGreen = "\033[102m";
	const std::string lightYellow = "\033[103m";
	const std::string lightBlue = "\033[104m";
	const std::string lightMagenta = "\033[105m";
	const std::string lightCyan = "\033[106m";
	const std::string lightWhite = "\033[107m";

	// Other
	const std::string reset = "\033[49m";
};