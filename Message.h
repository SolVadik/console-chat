#pragma once
#include <string>
#include "User.h"

class Message
{
	const std::string from_;
	const std::string to_;
	const std::string text_;
public:
	Message(std::string& from, std::string& to, std::string& text) :
		from_(from), to_(to), text_(text) {};
	
	//~Message() = default;

	const std::string& get_from() const { return from_; };
	const std::string& get_to() const { return to_; };
	const std::string& get_text() const { return text_; };
};
