#include<iostream>
#include<Exodo.h>

using namespace ExodoEngine;
using namespace graphics;
using namespace render;

//Construct Engine
Exodo exodo("Game Demo", 800, 600);

render::Shape triangle;

render::Entity player;

void Exodo::load() const{
	

}

void Exodo::create(Window window) const{

	exodo.setFullScreen(false, true);

	player = exodo.Entity.create();

	triangle = exodo.Shape.rectangle(0, 0, 200,100);

	triangle.Body.x = 0;

}

void Exodo::render() const {

	triangle.draw();

}

void Exodo::update() const{

	//triangle.Body.x += -0.004f;
	//(exodo.Input.isJoyButtonPressed(GLFW_JOYSTICK_1));
	
	if (exodo.Input.isKeyPressed(GLFW_KEY_LEFT)) {
		triangle.Body.x += -0.004f;
	}
	if (exodo.Input.isKeyPressed(GLFW_KEY_RIGHT)) {
		triangle.Body.x -= -0.004f;
	}
}

void Exodo::unload() const{
	

	std::cout << "Bye";
}



int main(int argc, char *argv[]){

	//Before Start application
	

	return 0;
}

