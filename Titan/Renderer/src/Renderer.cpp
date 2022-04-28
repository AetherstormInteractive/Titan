#include "Renderer.h"

namespace Titan
{
	void Renderer::init(GLFWwindow* win)
	{
		engine = filament::Engine::create();
		swapChain = engine->createSwapChain(glfwGetWin32Window(win));
		renderer = engine->createRenderer();

		camera = engine->createCamera(utils::EntityManager::get().create());
		view = engine->createView();
		scene = engine->createScene();

		skybox = filament::Skybox::Builder().color({ 0.1, 0.125, 0.25, 1.0 }).build(*engine);
		scene->setSkybox(skybox);
		view->setPostProcessingEnabled(false);
	}

	bool Renderer::update(GLFWwindow* win, uint32_t win_w, uint32_t win_h)
	{
		camera->setExposure(16.0f, 1 / 125.0f, 100.0f);
		camera->setExposure(100.0f);
		camera->setProjection(45.0f, float(win_w) / win_h, 0.1f, 100.0f);
		camera->lookAt({ 0, 0, 10.0 }, { 0, 0, 0 }, { 0, 1, 0 });

		view->setViewport({ 0, 0, win_w, win_h });
		view->setScene(scene);
		view->setCamera(camera); /* When we don't set the camera we run into a segfault. */
		return true;
	}

	void Renderer::render()
	{
		if (renderer->beginFrame(swapChain))
		{
			renderer->render(view);
			renderer->endFrame();
		}
	}

	void Renderer::draw()
	{
	}

	void Renderer::release()
	{
	}

}