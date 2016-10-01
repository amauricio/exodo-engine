#pragma once
#include"graphics\window.h";
#include"render\box.h";
#include"render\shape.h";
#include"render\entity.h";
#include"input\input.h";

namespace ExodoEngine {

	class Exodo {
	public:
		Exodo(const char *title, int width, int height);
		~Exodo();
		void load() const;
		void create(graphics::Window window) const;
		void render() const;
		void update() const;
		void unload() const;

		//SET

		void setFullScreen(bool isisFullScreen,  bool isWindowed);
		
		//External
		input::Input Input;
		render::Shape Shape;
		render::Entity Entity;
	private:
		graphics::Window pWindowEngine;
		const char *pTitle;
		int pWidth;
		int pHeight;
		bool isFullScreen;
		bool isWindowed;
	};

}