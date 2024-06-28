//- В методе record файл закрывается после первой записи, что приведет к тому, что последующие вызовы этого метода не смогут записывать данные.
//- Метод reading повторно открывает файл без проверки его состояния. Если файл уже открыт, это может привести к некорректному поведению.#include "Chat.h"

int main()
{
	Chat chat;
	chat.startChat();

	while (chat.work())
	{
		chat.showLoginMenu();
		while (chat.getcurrentUser())
		{
			chat.showUserMenu();
		}
	}

	return 0;
}
