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
	std::cout << "Number for choise: \n 1 - Login \n 2 - SignUp \n q - Out " << std::endl;
	std::cin >> operation;
	switch (operation) {
	case '1': {
		login();
		break;
	}
	case '2': {
		try
		{
			sign_up();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		break;
	}
	case 'q': {
		is_chat_work_ = false;
		break;
	}
	default: {
		std::cout << "enter 1 - 2 or q" << std::endl;
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

	if (get_user_login(login))
		throw UserLoginExp();

	std::cout << "Enter name: " << std::endl;
	std::cin >> name;

	if (get_user_name(name))
		throw UserNameExp();

	std::cout << "Enter password: " << std::endl;
	std::cin >> password;
	std::cout << std::endl;

	User<std::string> user(login, name, password);
	users_.push_back(user);
}

void Chat::show_user_menu()
{
	char operation{ 0 };
	std::cout << "Enter: \n 1 - Read message \n 2 - Add message \n 3 - Viev users \n 4 - Change name \n 5 - Change password \n q - Logout"
		<< std::endl;
	std::cin >> operation;
	switch (operation) {
	case '1': {
		show_chat();
		break;
	}
	case '2': {
		add_message();
		break;
	}
	case '3': {
		show_all_user_name();
		break;
	}
	case '4': {
		try
		{
			change_name();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		break;
	}
	case '5': {
		change_password();
		break;
	}
	case 'q': {
		current_user_ = nullptr;
		break;
	}
	default: {
		std::cout << "enter 1 - 5 or q" << std::endl;
		break;
	}
	}
}

void Chat::change_name()
{
	std::string name{ 0 };
	std::cout << "Enter new name: " << std::endl;
	std::cin >> name;
	if (get_user_name(name))
		throw UserNameExp();
	for (auto& user : users_) {
		if (current_user_->get_login() == user.get_login()) {
			user.set_name(name);
			return;
		}
	}
	
}

void Chat::change_password()
{
	std::string password{ 0 };
	std::cout << "Enter new password: " << std::endl;
	std::cin >> password;
	for (auto& user : users_) {
		if (current_user_->get_login() == user.get_login()) {
			user.set_password(password);
			return;
		}
	}
}

void Chat::show_chat() const
{
	/*for (int i = 0; i < messages_.size(); i++)
	{
		messages_[i].show_message();
	}*/
}

void Chat::show_all_user_name() const
{
	/*for (int i = 0; i < users_.size(); i++)
	{
		users_[i].show_name();
	}*/

	for (auto& user : users_)
	{
		std::cout << user.get_name() << std::endl;
	}
}

void Chat::add_message()
{
	/*std::string From = get_user_name();
	std::string To;
	std::cin >> To;
	std::string Text;
	std::cin >> Text;
	Message<std::string> message(From, To, Text);
	messages_.push_back(message);*/
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

