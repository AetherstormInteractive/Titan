#include <iostream>
#include <chrono>

#include "Application.h"
#include "Window.h"


using Clock = std::chrono::steady_clock;
using namespace std::literals;
auto constexpr dt = 1.0s / 60.;
using duration = std::chrono::duration<double>;
using time_point = std::chrono::time_point<Clock, duration>;

namespace Titan
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		time_point t{};

		time_point currentTime = Clock::now();
		duration accumulator = 0s;

		//Renderer* ren = new Renderer();
		Window* win = new Window();
		//win->setRenderer(ren);
		//ren->setWindow(win);
		win->init();

		win->run();
		//update

	}


}

