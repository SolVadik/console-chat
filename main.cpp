//console chat
#include "Chat.h"

int main()
{
	Chat chat;

	chat.start();

	while (chat.is_chat_work()){
		chat.show_login_menu();
		while (chat.get_current_user()) {
			chat.show_user_menu();
		}
	}
	return 0;
}