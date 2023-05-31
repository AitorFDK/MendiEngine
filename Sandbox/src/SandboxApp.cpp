#include <MendiEngine.h>

class Sandbox : public MendiEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

MendiEngine::Application* MendiEngine::CreateApplication() {
	return new Sandbox();
}