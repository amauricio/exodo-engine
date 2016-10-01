#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include "body.h";
#include <iostream>
namespace ExodoEngine {
	namespace render {

#define EXODO_SHAPE_TRIANGLE	0
#define EXODO_SHAPE_RECTANGLE	1

		class Shape {
		public:
			Shape() {};
			void draw();
			int type;
			static float xPush;
			Body Body;
			inline Shape triangle(float a, float b, float c) { 
				Shape g;
				g.type = EXODO_SHAPE_TRIANGLE;
				return g;
			};
			inline Shape rectangle(double x, double y, double width, double height) {
				Shape g;
				g.type = EXODO_SHAPE_RECTANGLE;
				Body.x = x;
				return g;
			};
		};
		

	}
}
#endif