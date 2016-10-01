#include "input.h";

namespace ExodoEngine {
	namespace input {

		bool Input::pKeys[MAX_KEYS];
		bool Input::pButtons[MAX_BUTTONS];
		double Input::pMX;
		double Input::pMY;

		

		void Input::joystick_callback(int joy, int event)
		{
			if (event == GLFW_CONNECTED)
			{
				std::cout << "Connected \n";

			}
			else if (event == GLFW_DISCONNECTED)
			{
				std::cout << "DisConnected \n";
			}
		}

		void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Input::pKeys[key] = action != GLFW_RELEASE;
		}
		void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Input::pButtons[button] = action != GLFW_RELEASE;
		}
		void Input::cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
		{
			Input::pMX = xpos;
			Input::pMY = ypos;
		}
		void Input::clear_input()
		{
			for (int i = 0; i < MAX_KEYS; i++) {
				pKeys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				pButtons[i] = false;
			}

		}

		bool Input::isKeyPressed(int keycode)
		{
			if (keycode >= MAX_KEYS)
				return false;
			return Input::pKeys[keycode];
		}


		bool Input::isMouseButtonPressed(int button)
		{
			if (button >= MAX_BUTTONS)
				return false;
			return Input::pButtons[button];
		}

		void Input::getMousePosition(double& x, double& y)
		{
			x = pMX;
			y = pMY;
		}

		bool Input::joy_button()
		{

			//Clear joystick press
			input::Joystick::clear_input();

			int present = glfwJoystickPresent( GLFW_JOYSTICK_1 );

			input::Joystick::isRight = false;
			input::Joystick::isLeft = false;
			input::Joystick::isTop = false;
			input::Joystick::isBottom = false;

			input::Joystick::isX = false;
			input::Joystick::isY = false;

			if (1 == present) {

				//Axis
				int count;
				const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);
				
				//X Axis
				if ( -1 == axes[0] ) {
					input::Joystick::isLeft = true;
					input::Joystick::isX = true;
				}
				if ( 1 == axes[0]) {
					input::Joystick::isRight = true;
					input::Joystick::isX = true;
				}
				//Y Axis
				if (-1 == axes[1]) {
					input::Joystick::isTop = true;
					input::Joystick::isY = true;
				}
				if (1 == axes[1]) {
					input::Joystick::isBottom = true;
					input::Joystick::isY = true;
				}

				//Buttons

				int ns;
				const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &ns);
				for (int i = 0; i < JOY_BUTTONS; i++) {
					if (GLFW_PRESS == buttons[i]) {
						input::Joystick::jButtons[i] = true;
					}
					else if (GLFW_RELEASE == buttons[i]) {
						input::Joystick::jButtons[i] = false;
					}
				}
				

			}
			
			return true;

		}

		
	}
}