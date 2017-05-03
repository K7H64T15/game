#include <iostream>
#include "GLWindow.h"
#include "Constants.h"
#include "SettingsManager.h"

std::string GLWindow::current = MENU_FRAME;
std::map<const std::string, GLFrame*> *GLWindow::frames = new std::map<const std::string, GLFrame*>();
bool GLWindow::shouldClose = false;
static void onMouseMove(GLFWwindow * window, double xpos, double ypos);
void onMouseClick(GLFWwindow* window, int button, int action, int mods);

GLWindow::GLWindow()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    unsigned int screenWidth = stoul(SettingsManager::getInstance()->getValue(SettingsManager::SCREEN_WIDTH));
    unsigned int screenHeight = stoul(SettingsManager::getInstance()->getValue(SettingsManager::SCREEN_HEIGHT));

	window = glfwCreateWindow(screenWidth, screenHeight, "Soul Rift", glfwGetPrimaryMonitor(), NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	glewExperimental = (GLboolean) true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glfwSetCursorPosCallback(window, onMouseMove);
    glfwSetMouseButtonCallback(window, onMouseClick);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLFrame *menuFrame = new GLFrame();
	GLWindow::frame = menuFrame;
    (*GLWindow::frames)[MENU_FRAME] = menuFrame;
	GLFrame *gameFrame = new GLFrame();
	GLFrame *settingsFrame = new GLFrame();
    (*GLWindow::frames)[GAME_FRAME] = gameFrame;
    (*GLWindow::frames)[SETTINGS_FRAME] = settingsFrame;
}

void GLWindow::loop()
{
	do {
		glClear(GL_COLOR_BUFFER_BIT);
		GLWindow::frame->draw();
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0 && !shouldClose);
}

static void onMouseMove(GLFWwindow * window, double xpos, double ypos)
{

    std::list<GLObject *> objects = (*GLWindow::frames)[GLWindow::current]->getChildren();
    for (std::list<GLObject *>::const_iterator iterator = objects.begin(),
                 end = objects.end(); iterator != end; ++iterator) {
        if ((*iterator)->getCoordinates()->leftX <= xpos && (*iterator)->getCoordinates()->rightX >= xpos &&
            (*iterator)->getCoordinates()->bottomY <= ypos && (*iterator)->getCoordinates()->topY >= ypos) {
            ((*iterator)->getOmMouseMove())((*iterator), xpos - (*iterator)->getCoordinates()->leftX,
                                             ypos - (*iterator)->getCoordinates()->bottomY);
        }
        else
        {
            (*iterator)->deactivate();
        }
    }
}

void onMouseClick(GLFWwindow* window, int button, int action, int mods)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    std::list<GLObject *> objects = (*GLWindow::frames)[GLWindow::current]->getChildren();
    for (std::list<GLObject *>::const_iterator iterator = objects.begin(),
                 end = objects.end(); iterator != end; ++iterator) {
        if ((*iterator)->getCoordinates()->leftX <= xpos && (*iterator)->getCoordinates()->rightX >= xpos &&
                (*iterator)->getCoordinates()->bottomY <= ypos && (*iterator)->getCoordinates()->topY >= ypos) {
            ((*iterator)->getOnMouseClick())((*iterator), button, action, mods,
                                             xpos - (*iterator)->getCoordinates()->leftX,
                                             ypos - (*iterator)->getCoordinates()->bottomY);
        }
    }
}

GLWindow::~GLWindow()
{
	glfwTerminate();
	//delete frame;
}

void GLWindow::loadCoordinates() {
	//TODO:: cleanup
//    mouseHandlers->clear();
//    std::list<Coordinates *> *coordinates = frame->getCoordinates();
//    std::list<mouseClick> *onMouseClick = frame->getOnMouseClickHandlers();
//    std::list<mouseClick>::const_iterator iterator2 = onMouseClick->begin(), end2 = onMouseClick->end();
//    for (std::list<Coordinates *>::const_iterator iterator = coordinates->begin(), end = coordinates->end();
//         iterator != end, iterator2 != end2; ++iterator, ++iterator2) {
//        MouseHandler *handler = new MouseHandler();
//        handler->coordinates = (*iterator);
//        handler->onMouseClick = (*iterator2);
//        mouseHandlers->push_back(*handler);
//    }
}

void GLWindow::setFrame(const std::string frame) {
	this->frame = (*frames)[frame];
    current = frame;
	loadCoordinates();
}

void GLWindow::closeWindow() {
    shouldClose = true;
}



