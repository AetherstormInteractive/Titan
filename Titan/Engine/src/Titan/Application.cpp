#include <iostream>
#include <chrono>

#include "Application.h"
#include "Window.h"
namespace Titan
{
	using namespace std::chrono_literals;

	// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
	constexpr std::chrono::nanoseconds timestep(16ms);
	double getCurrentTime() { return 0; }

	struct game_state
	{
		// this contains the state of your game, such as positions and velocities
	};

	game_state interpolate(game_state const& current, game_state const& previous, float alpha)
	{
		game_state interpolated_state;

		// interpolate between previous and current by alpha here

		return interpolated_state;
	}

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::FixedUpdate()
	{
		std::cout << "fixed" << std::endl;
	}

	void Application::Run()
	{
		Window* win = new Window();

		win->init();
		using clock = std::chrono::high_resolution_clock;

		std::chrono::nanoseconds lag(0ns);
		auto time_start = clock::now();
		bool quit_game = false;

		game_state current_state;
		game_state previous_state;

		while (!quit_game)
		{
			auto delta_time = clock::now() - time_start;
			time_start = clock::now();
			lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

			// update game logic as lag permits
			while (lag >= timestep)
			{
				lag -= timestep;

				previous_state = current_state;
				FixedUpdate();
			}

			// calculate how close or far we are from the next timestep
			auto alpha = (float)lag.count() / timestep.count();
			auto interpolated_state = interpolate(current_state, previous_state, alpha);
			win->run();
		}
			//win->run();

		//Renderer* ren = new Renderer();
		//win->setRenderer(ren);
		//ren->setWindow(win);
		//update

	}


}

