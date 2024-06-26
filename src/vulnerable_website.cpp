﻿/*
Author: Ashley Jones
This small script logs into the website http://testphp.vulnweb.com.
It does this by using hardcoded parameters, uname, pass and using the script /userinfo.php.
*/

// project include
#include "utils.h"
#include "vulnerable_website.h"
// lib include
#include "httplib.h"
// STL include
#include <iostream>
#include <tuple> 


int main()
{
	std::string url = "http://testphp.vulnweb.com", loginPath = "/login.php";
	httplib::Result loginPageData, loginResult;
	httplib::Client cli(url);

	utils::promptUserToStart();

	loginPageData = cli.Get(loginPath);

	utils::LoginForm login(loginPageData->body);

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

	utils::promptUserToEnd();

	return 0;
}

