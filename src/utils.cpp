#include <tuple>
#include <string>
#include "httplib.h"
#include "utils.h"

namespace utils {

void promptUserToStart() {
	std::string line;
	std::cout << "Please enter any key to start process: ";
	std::getline(std::cin, line);
	std::cout << std::endl;
}


void promptUserToEnd() {
	std::string line;
	std::cout << "Please enter any key to end process: ";
	std::getline(std::cin, line);
	std::cout << std::endl;
}


std::tuple<std::string, std::string, std::string> LoginForm::extractFormData(const std::string& data) {
	// pretending as though we are parsing for now. 
	return { "uname", "pass", "/userinfo.php" };
}


LoginForm::LoginForm(const std::string& pageData) {
	auto formData = extractFormData(pageData);

	this->uname = std::get<0>(formData);
	this->pass = std::get<1>(formData);
	this->formScript = std::get<2>(formData);
}


httplib::Params LoginForm::createLoginParams() {
	httplib::Params loginParams{
			{ uname, "test" },
			{ pass, "test" }
	};
	return loginParams;
}
} // end of utils