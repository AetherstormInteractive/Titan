#pragma once
#include <stdio.h>
#include "Core.h"

#include "Renderer.h"

namespace Titan
{
	class TITAN_API Window
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


