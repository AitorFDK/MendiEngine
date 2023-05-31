#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MendiEngine {
	class MENDI_ENGINE_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ME_CORE_TRACE(...) ::MendiEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ME_CORE_INFO(...)  ::MendiEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ME_CORE_WARN(...)  ::MendiEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ME_CORE_ERROR(...) ::MendiEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ME_CORE_FATAL(...) ::MendiEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ME_TRACE(...) ::MendiEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ME_INFO(...)  ::MendiEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ME_WARN(...)  ::MendiEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ME_ERROR(...) ::MendiEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ME_FATAL(...) ::MendiEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)