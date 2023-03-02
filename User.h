#pragma once
#include <string>


class User
{
	const std::string login_;
	std::string name_;
	std::string password_;
public:
	User(const std::string& login, const std::string& name, const std::string& password) :
		login_(login), name_(name), password_(password) {};
	
	//~User() = default;

	const std::string& get_login() const { return login_; };
	const std::string& get_name() const { return name_; };
	const std::string& get_password() const { return password_; };

	void set_name(const std::string& name) { name_ = name; };
	void set_password(const std::string& password) { password_ = password; };
};

