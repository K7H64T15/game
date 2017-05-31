// Include standard headers
#include "GameWindow.h"


int main()
{
	GameWindow *win = GameWindow::getInstance();
	win->loop();
	delete win;
	return 0;
}

