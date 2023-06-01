#pragma once

#include "MendiEngine/Core.h"

namespace MendiEngine {

	// Events are currently blocking, we need to save it in buffer and dispatch it on Event stage.

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		Application		= BIT(0), // 1 << 0
		Input			= BIT(1), // 1 << 1
		Keyboard		= BIT(2), // 1 << 2
		Mouse			= BIT(3), // 1 << 3
		MouseButton		= BIT(4)  // 1 << 4

	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class MENDI_ENGINE_API Event {

		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCateogry(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	protected:
		bool _handled = false;

	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) : _event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T>func) {
			if (_event.GetEventType() == T::GetStaticType())
			{
				_event._handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}
	private:
		Event& _event;
	};

	inline std::ostream& operator << (std::ostream os, const Event& e)
	{
		return os << e.ToString();
	}

}