#include "body.h";
#include "../GLFW/glfw3.h";

namespace ExodoEngine {
	namespace render {

		void Body::setX(double new_x)
		{
			this->x = new_x;
		}
		double Body::getX()
		{
			return this->x;
		}
	}
}
