#pragma once

#include "Event.h"

#include <sstream>

namespace MendiEngine {

	class MENDI_ENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return _keycode; }

		EVENT_CLASS_CATEGORY(Keyboard | Input)

	protected:
		KeyEvent(int keycode) : _keycode(keycode) {}

		int _keycode;
	};

	class MENDI_ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return _repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keycode << " (" << _repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	protected:
		int _repeatCount;
	};

	class MENDI_ENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}