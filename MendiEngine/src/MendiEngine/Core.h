#pragma once

#ifdef ME_PLATFORM_WINDOWS

	#ifdef ME_BUILD_DLL
		#define MENDI_ENGINE_API __declspec(dllexport)
	#else
		#define MENDI_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error Mendi Engine only support Windows!
#endif

#define BIT(x) (1 << X)
