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


class LoginForm {
	std::tuple<std::string, std::string, std::string> extractFormData(const std::string& data) {
		// pretending as though we are parsing for now. 
		return { "uname", "pass", "/userinfo.php" };
	}

public: 
	std::string uname, pass, formScript;

	LoginForm(const std::string& pageData) {
		auto formData = extractFormData(pageData);
		
		this->uname = std::get<0>(formData);
		this->pass = std::get<1>(formData);
		this->formScript = std::get<2>(formData);
	}

	httplib::Params createLoginParams() {
		httplib::Params loginParams{
			  { uname, "test" },
			  { pass, "test" }
		};
		return loginParams;
	}
};


int main()
{
	std::string url = "http://testphp.vulnweb.com", loginPath = "/login.php";
	httplib::Result loginPageData, loginResult;
	httplib::Client cli(url);

	promptUserToStart();

	loginPageData = cli.Get(loginPath);

	LoginForm login(loginPageData->body);

	loginResult = cli.Post(
		login.formScript, 
		login.createLoginParams()
	);

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
