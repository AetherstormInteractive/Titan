#include <iostream>
#include "Window.h"

int win_w, win_h;

namespace Titan
{
	void Window::init()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		window = glfwCreateWindow(1600, 900, "Titan Game", NULL, NULL);
		isRunning = true;
		ren->init(window);

	}

	void Window::run()
	{
		std::cout << "render" << std::endl;
			glfwGetWindowSize(window, &win_w, &win_h);
			ren->update(window, win_w, win_h);
			ren->render();
			glfwSwapBuffers(window);
			glfwPollEvents();
	}

	void Window::release()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		delete ren;
	}

}