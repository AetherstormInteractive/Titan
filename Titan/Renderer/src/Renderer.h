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
		void init(GLFWwindow* win);
		bool update(GLFWwindow* win, uint32_t win_w, uint32_t win_h);
		void render();
		void draw();
		void release();
	};
}


