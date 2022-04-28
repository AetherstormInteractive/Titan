#pragma once
#include <cstdio>

#include "utils/EntityManager.h"
#include "filament/Engine.h"
#include "filament/SwapChain.h"
#include "filament/Renderer.h"
#include "filament/View.h"
#include "filament/Scene.h"
#include "filament/Skybox.h"
#include "filament/Material.h"
#include "filamat/MaterialBuilder.h"
#include "filament/Camera.h"
#include "filament/Viewport.h"

#include <filament/MaterialInstance.h>


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

		filament::Engine* engine;
		filament::SwapChain* swapChain;
		filament::Renderer* renderer;

		filament::Camera* camera;
		filament::View* view;
		filament::Scene* scene;

		filament::Skybox* skybox;
	};
}


