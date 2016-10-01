#pragma once
#ifndef KEY_H
#define KEY_H

#include<iostream>
#include "../GLFW/glfw3.h";
#include "joystick.h";

namespace ExodoEngine {
	namespace input {

	#define MAX_KEYS	1024
	#define MAX_BUTTONS	32

		class Input {
		public:
			Input() {}
		private:
			static bool pKeys[MAX_KEYS];
			static bool pButtons[MAX_BUTTONS];
			static double pMX, pMY;
			
		public:
			static bool isKeyPressed(int keycode);
			static bool isMouseButtonPressed(int button);
			
			static bool joy_button();

			static Joystick Joystick;
			
			static void getMousePosition(double& x, double& y);

			static void joystick_callback(int joy, int event);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

			static void clear_input();
		};
		
	}
}

#endif;