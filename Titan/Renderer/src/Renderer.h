#pragma once
#include <cstdio>

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

namespace Titan
{
	class Renderer
	{
	public:
		bool init(GLFWwindow* win);
		void render();
		void draw();
		void release();
	};
}


