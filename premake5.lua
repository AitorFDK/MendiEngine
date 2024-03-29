workspace "MendiEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MendiEngine"
	location "MendiEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mepch.h"
	pchsource "MendiEngine/src/mepch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ME_PLATFORM_WINDOWS",
			"ME_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ME_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ME_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"MendiEngine/vendor/spdlog/include",
		"MendiEngine/src"
	}

	links {
		"MendiEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ME_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "ME_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ME_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		optimize "On"
