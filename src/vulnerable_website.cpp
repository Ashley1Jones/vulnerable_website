#include <any>
#include "vulnerable_website.h"
#include "httplib.h"
#include <iostream>
#include<tuple> 


void promptUserToStart() {
	std::string line;
	std::cout << "Please enter any key to start process: ";
	std::getline(std::cin, line);
	std::cout << std::endl;
}


void promptUserToEnd() {
	std::string line;
	std::cout << "Please enter any key to login: ";
	std::getline(std::cin, line);
	std::cout << std::endl;
}


std::tuple<std::string, std::string, std::string> parseFormData(std::string data) {
	// pretending as though we are parsing for now. 
	return { "uname", "pass", "/userinfo.php" };
}


int main()
{
	getInfo();

	std::string url = "http://testphp.vulnweb.com";
	httplib::Client cli(url);

	std::string loginPath = "/login.php";
	httplib::Result loginPageData = cli.Get(loginPath);

	auto formData = parseFormData(loginPageData->body);

	std::string uname = std::get<0>(formData), 
		pass = std::get<1>(formData), 
		formName = std::get<2>(formData);


	httplib::Params params{
	  { uname, "test" },
	  { pass, "test" }
	};

	httplib::Result res = cli.Post(formName, params);

	promptUserToEnd();

	return 0;
}
