#pragma once
#ifndef BODY_H
#define BODY_H

#include "../GLFW/glfw3.h";

namespace ExodoEngine {
	namespace render {
		class Body {
		public:
			Body() {}
			double x = 0;
			double y = 0;
			void setX(double new_x);
			double getX();
		};
	}
}
#endif