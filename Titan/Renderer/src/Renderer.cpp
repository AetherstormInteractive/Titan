#include "Renderer.h"
#include "utils/EntityManager.h"
#include "filament/Engine.h"
#include "filament/SwapChain.h"
#include "filament/Renderer.h"
#include "filament/View.h"

namespace Titan
{

	bool Renderer::init(GLFWwindow* win)
	{
		filament::Engine* engine = filament::Engine::create();
		filament::SwapChain* swapChain = engine->createSwapChain(glfwGetWin32Window(win));
		filament::Renderer* renderer = engine->createRenderer();

		filament::Camera* camera = engine->createCamera(utils::EntityManager::get().create());
		filament::View* view = engine->createView();
		filament::Scene* scene = engine->createScene();

		view->setCamera(camera);
		view->setScene(scene);
		return true;
	}

	unsigned int counter = 0;

	void Renderer::render()
	{

	}

	void Renderer::draw()
	{
	}

	void Renderer::release()
	{
	}

}