#pragma once

#ifdef ME_PLATFORM_WINDOWS

extern MendiEngine::Application* MendiEngine::CreateApplication();

int main(int argc, char** argv) {
	
	MendiEngine::Log::Init();
	
	ME_CORE_WARN("Initizlied Log!");
	int a = 5;
	ME_INFO("Hello world for {0}", a);

	auto app = MendiEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif