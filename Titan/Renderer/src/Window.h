#pragma once
#include <stdio.h>

#include "Renderer.h"

namespace Titan
{
	class __declspec(dllexport) Window
	{
	public:

		Renderer* ren = new Renderer();
		void init();
		void run();
		void release();

		bool isRunning = false;
		GLFWwindow* window;
	};
}


