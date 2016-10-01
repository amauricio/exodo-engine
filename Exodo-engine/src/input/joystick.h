#pragma once

namespace ExodoEngine {
	namespace input {

#define JOY_BUTTONS  16

		class Joystick {
		public:
			Joystick() {};
			~Joystick() {};
			static bool isLeft;
			static bool isRight;
			static bool isTop;
			static bool isBottom;

			//Axis
			static bool isX;
			static bool isY;

			//Buttons
			static bool jButtons[JOY_BUTTONS];

			static int getAxis();
			static bool isKeyPressed(int button);
			static bool isKeyReleased(int button);

			static void clear_input();
		};
	}
}