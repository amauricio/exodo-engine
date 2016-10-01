#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include<iostream>
#include "../GLFW/glfw3.h";

namespace ExodoEngine {
	namespace graphics {

		class Window {
		public:
			const char *pName;
			int pWidth, pHeight;
			GLFWwindow *pWindow;
			bool pClose;
			bool isFullScreen;
			bool isWindowed;
		public:
			Window();
			Window(const char *name, int width, int height);
			~Window();
			void clear() const;
			bool closed() const;
			void terminate() const;
			void update();
			void render(const char *name, int width, int height);

			friend static void reshape_scene(GLFWwindow * window, int width, int height, float aspect);
			friend static void window_resize(GLFWwindow *window, int width, int height);

			inline int getWidth() { return pWidth; }
			inline int getHeight() { return pHeight; }


		public:
			void setFullScreen(bool is, bool isWindowed);
			bool init();
		};

	}
}
#endif