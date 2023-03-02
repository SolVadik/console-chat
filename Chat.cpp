#pragma once
#include <iostream>
#include "Chat.h"

void Chat::start()
{
	is_chat_work_ = true;
	//User user1("1", "1", "1");
	//User user2("2", "2", "2");
	//User user3("3", "3", "3");
	//users_.push_back(user1);
	//users_.push_back(user2);
	//users_.push_back(user3);
}

void Chat::show_login_menu()
{
	char operation;
	std::cout << "Number for choise: \n 1 - Login \n 2 - SignUp \n 3 - Out " << std::endl;
	std::cin >> operation;
	switch (operation) {
	case '1': {
		std::cout << "1" << std::endl;
		login();
		break;
	}
	case '2': {
		std::cout << "2" << std::endl;
		sign_up();
		break;
	}
	case '3': {
		std::cout << "3" << std::endl;
		is_chat_work_ = false;
		break;
	}
	default: {
		std::cout << "enter 1 - 2 or 3" << std::endl;
		break;
	}
	}
}

void Chat::login()
{
	std::cout << "4" << std::endl;
}

void Chat::sign_up()
{
	std::cout << "5" << std::endl;
}

void Chat::show_user_menu()
{
	std::cout << "6" << std::endl;
}

void Chat::show_chat() const
{
	std::cout << "7" << std::endl;
}

void Chat::show_all_user_name() const
{
	std::cout << "8" << std::endl;
}

void Chat::add_message()
{
	std::cout << "9" << std::endl;
}

std::shared_ptr<User> Chat::get_user_login(const std::string& login) const
{
	std::cout << "10" << std::endl;
	return std::shared_ptr<User>();
}

std::shared_ptr<User> Chat::get_user_name(const std::string& name) const
{
	std::cout << "11" << std::endl;
	return std::shared_ptr<User>();
}
