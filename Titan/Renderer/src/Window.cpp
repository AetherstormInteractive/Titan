#include "Window.h"

#define WNDW_WIDTH 1600
#define WNDW_HEIGHT 900

namespace Titan
{
	void Window::init()
	{
		glfwInit();
		window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "Titan Game", NULL, NULL);
		ren->init(window);
		isRunning = true;
		if (!ren->init(window))
		{
			printf("Renderer could not be initialized!\n");
		}
		else
		{
			printf("Renderer running!\n");
		}

	}

	void Window::run()
	{
		while (!glfwWindowShouldClose(window))
		{
			ren->render();
			glfwPollEvents();
		}
	}

	void Window::release()
	{
		bgfx::shutdown();
		glfwDestroyWindow(window);
		glfwTerminate();
	}

}