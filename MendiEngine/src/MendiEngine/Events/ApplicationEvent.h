#pragma once

#include "Event.h"

namespace MendiEngine {

	class MENDI_ENGINE_API WindowResizeEvent : public Event 
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : _width(width), _height(height) {}

		inline unsigned int GetWidth() const { return _width; }
		inline unsigned int GetHeight() const { return _height; }

		std::string ToString() {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _width << ", " << _height;
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(Application)

	private:
		unsigned int _width, _height;
	};

	class MENDI_ENGINE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(unsigned int x, unsigned int y) : _x(x), _y(y) {}

		inline unsigned int GetX() const { return _x; }
		inline unsigned int GetY() const { return _y; }

		std::string ToString() {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _x << ", " << _y;
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(Application)

	private:
		int _x, _y;
	};

	class MENDI_ENGINE_API WindowCloseEvent : public Event 
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(Application)
	};

	class MENDI_ENGINE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(Application)
	};

	class MENDI_ENGINE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(Application)
	};

	class MENDI_ENGINE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(Application)
	};
}