#include <Titan.h>

class GameApplication : public Titan::Application
{
public:
	GameApplication()
	{

	}

	~GameApplication()
	{

	}
};

Titan::Application* Titan::CreateApp()
{
	return new GameApplication();
}