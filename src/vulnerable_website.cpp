#include <any>
#include "vulnerable_website.h"
#include "httplib.h"
#include <iostream>
#include<tuple> 


void getInfo() {
	std::string line;
	std::cout << "Please enter any key to login: " << std::endl;
	std::getline(std::cin, line);
}


std::tuple<std::string, std::string, std::string> parseFormData(std::string data) {
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

	std::cout << res->body << std::endl;

	return 0;
}
