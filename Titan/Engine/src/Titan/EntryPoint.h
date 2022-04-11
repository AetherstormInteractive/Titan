#pragma once
#ifdef TITAN_WINDOWS 
extern Titan::Application* Titan::CreateApp();

int main(int argc, char** argv)
{
	printf("Aetherstorm Interactive (c) 2022\n================================\nTitan Engine\n================================\n");
	auto app = Titan::CreateApp();
	app->Run();
	delete app;
	return 0;
}
#endif