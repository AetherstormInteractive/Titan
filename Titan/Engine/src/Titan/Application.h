#pragma once
#include "Core.h"

namespace Titan
{
	class TITAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void FixedUpdate();
	};

	Application* CreateApp();
}


