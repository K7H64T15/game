// Include standard headers
#include <iostream>
#include "GameWindow.h"
#define TESTS

int main()
{
#ifdef TESTS
    std::cout << "TESTS" << std::endl;
#else
	GameWindow *win = GameWindow::getInstance();
	win->loop();
	delete win;
#endif
	return 0;
}

