#pragma once
#include <iostream>
#include "Chat.h"

void Chat::start()
{
	is_chat_work_ = true;
	User<std::string> user1("1", "1", "1");
	User<std::string> user2("2", "2", "2");
	User<std::string> user3("3", "3", "3");
	users_.push_back(user1);
	users_.push_back(user2);
	users_.push_back(user3);
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
	std::string login{ 0 }, password{ 0 };
	char operation{ 0 };

	do {
		std::cout << "Enter login: " << std::endl;
		std::cin >> login;

		std::cout << "Enter password: " << std::endl;
		std::cin >> password;
		std::cout << std::endl;

		current_user_ = get_user_login(login);

		if (current_user_ == nullptr || (password != current_user_->get_password())) {
			current_user_ == nullptr;
			std::cout << "Login or password failed" << std::endl;
			std::cout << "Enter q for exit or any key repeat: " << std::endl;
			std::cin >> operation;
			if (operation == 'q')
				break;
		}
	} while (!current_user_);
}

void Chat::sign_up()
{
	std::string login{ 0 }, name{ 0 }, password{ 0 };

	std::cout << "Enter login: " << std::endl;
	std::cin >> login;

	std::cout << "Enter name: " << std::endl;
	std::cin >> name;

	std::cout << "Enter password: " << std::endl;
	std::cin >> password;
	std::cout << std::endl;

	User<std::string> user(login, name, password);
	users_.push_back(user);
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

std::shared_ptr<User<std::string>> Chat::get_user_login(const std::string& login) const
{
	for (auto& user : users_)
	{
		if (login == user.get_login())
			return std::make_shared<User<std::string>>(user);

	}
	return nullptr;
}

std::shared_ptr<User<std::string>> Chat::get_user_name(const std::string& name) const
{
	for (auto& user : users_)
	{
		if (name == user.get_name())
			return std::make_shared<User<std::string>>(user);

	}
	return nullptr;
}
