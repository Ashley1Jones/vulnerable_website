/*
Author: Ashley Jones
This small script logs into the website http://testphp.vulnweb.com.
*/

#include "vulnerable_website.h"
#include "httplib.h"
#include <iostream>
#include <tuple> 


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


std::tuple<std::string, std::string, std::string> parseFormData(const std::string& data) {
	// pretending as though we are parsing for now. 
	return { "uname", "pass", "/userinfo.php" };
}


int main()
{
	promptUserToStart();

	std::string url = "http://testphp.vulnweb.com";
	httplib::Client cli(url);

	std::string loginPath = "/login.php";
	httplib::Result loginPageData = cli.Get(loginPath);

	auto formData = parseFormData(loginPageData->body);

	std::string uname = std::get<0>(formData), 
		pass = std::get<1>(formData), 
		formName = std::get<2>(formData);

	httplib::Params loginParams{
	  { uname, "test" },
	  { pass, "test" }
	};

	httplib::Result loginResult = cli.Post(formName, loginParams);

	std::cout << loginResult->body << std::endl;

	switch (loginResult->status) {
	case SUCCESS_CODE:
		std::cout << "Success!" << std::endl;
		break;
	default:
		std::cerr << "Failed to access website with code: " << loginResult->status << std::endl;
		break;
	}

	std::cout << loginResult->body << std::endl;

	promptUserToEnd();

	return 0;
}
