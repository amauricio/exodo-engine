#include "shape.h"
#include <iostream>

namespace ExodoEngine {
	namespace render {

		void Shape::draw() 
		{

			glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glTranslatef(this->Body.getX(), 0, 0);
			switch (this->type)
			{
			case EXODO_SHAPE_TRIANGLE:

				glBegin(GL_TRIANGLES);
				glVertex2d(this->Body.getX(), -0.4f);
				glVertex2d(0.0f, 0.4f);
				glVertex2d(0.4f, -0.4f);
				break;
			case EXODO_SHAPE_RECTANGLE:
				glRotatef(10.0f, 50.0f, 1.0f, 1.3f);
				glBegin(GL_QUADS);
				glVertex3f(0, 0, 0);
				glVertex3f(1, 0, 0);
				glVertex3f(1, 1, 0);
				glVertex3f(0, 1, 0);
				break;
			default:
				break;
			}
			glEnd();
			glPopMatrix();
			
		}
		
	}
}