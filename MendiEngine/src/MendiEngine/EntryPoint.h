#pragma once

#ifdef ME_PLATFORM_WINDOWS

extern MendiEngine::Application* MendiEngine::CreateApplication();

int main(int argc, char** argv) {
	
	printf("Mendi Engine Running\n");
	auto app = MendiEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif