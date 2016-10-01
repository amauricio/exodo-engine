#pragma once
#ifndef BOX_H
#define BOX_H

#include<iostream>
#include "../GLFW/glfw3.h";

namespace ExodoEngine {
	namespace render {
		class Box {
		public:
			static void create(const char *id);
		private:
			Box() {}
		};
	}
}
#endif