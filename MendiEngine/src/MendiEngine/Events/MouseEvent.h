#pragma once

#include "Event.h"

namespace MendiEngine {
	class MENDI_ENGINE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : _mouseX(x), _mouseY(y) {}

		inline float GetX() const { return _mouseX; }
		inline float GetY() const { return _mouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(Mouse | Input)

	private:
		float _mouseX, _mouseY;
	};

	class MENDI_ENGINE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {}

		inline float GetXOffset() const { return _xOffset; }
		inline float GetYOffset() const { return _yOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _xOffset << ", " << _yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(Mouse | Input)

	private:
		float _xOffset, _yOffset;
	};

	class MENDI_ENGINE_API MouseButtonEvent : public Event
	{
	public:
		inline float GetButton() const { return _button; }

		EVENT_CLASS_CATEGORY(Mouse | Input)

	protected:
		MouseButtonEvent(int button) : _button(button) {}

	protected:
		int _button;
	};

	class MENDI_ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MENDI_ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}