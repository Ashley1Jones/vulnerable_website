/*
Dumping ground for functions and classes for now.
*/

#pragma once
#include <tuple>
#include <string>
#include "httplib.h"


void promptUserToStart();
void promptUserToEnd();

/*
Contains login form data given a html page
*/
class LoginForm {
	std::tuple<std::string, std::string, std::string> extractFormData(const std::string& data);
public:
	std::string uname, pass, formScript;
	LoginForm(const std::string& pageData);
	httplib::Params createLoginParams();
};