#include "joystick.h";

namespace ExodoEngine {
	namespace input {
		bool Joystick::isLeft = false;
		bool Joystick::isRight = false;
		bool Joystick::isTop = false;
		bool Joystick::isBottom = false;
		bool Joystick::isX = false;
		bool Joystick::isY = false;
		bool Joystick::jButtons[JOY_BUTTONS];

		int Joystick::getAxis()
		{
			if (Joystick::isTop && Joystick::isLeft) {
				return 2;
			}
			if (Joystick::isTop && Joystick::isRight) {
				return 4;
			}
			if (Joystick::isRight && Joystick::isBottom) {
				return 6;
			}
			if (Joystick::isBottom && Joystick::isLeft) {
				return 8;
			}

			if (Joystick::isLeft) {
				return 1;
			}
			
			if (Joystick::isTop) {
				return 3;
			}
			
			if (Joystick::isRight) {
				return 5;
			}
			
			if (Joystick::isBottom) {
				return 7;
			}
			
			return 0;
		}
		void Joystick::clear_input() {
				for (int i = 0; i < JOY_BUTTONS; i++) {
					jButtons[i] = false;
				}
		}
		bool Joystick::isKeyPressed(int button)
		{
			if (button >= JOY_BUTTONS)
				return false;
			return Joystick::jButtons[button];
		}
		bool Joystick::isKeyReleased(int button)
		{
			if (button >= JOY_BUTTONS)
				return true;
			return !Joystick::jButtons[button];
		}
	}
}