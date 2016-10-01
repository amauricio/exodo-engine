#include "Exodo.h";
#include "graphics\window.h";

namespace ExodoEngine {
	
	using namespace graphics;

		//constructor
	Window window;
	const char *ExodoTitle;
	int ExodoWidth;
	int ExodoHeight;


	Exodo::Exodo(const char *title, int width, int height) : pWindowEngine(pWindowEngine) {
		//Start
		
		ExodoTitle = title;
		ExodoWidth = width;
		ExodoHeight = height;

		std::cout << "EE > __CREATE__\n";

		load();
		create(this->pWindowEngine);

		window.setFullScreen(isFullScreen, isWindowed);
		window.render(ExodoTitle, ExodoWidth, ExodoHeight);
		
		this->pWindowEngine = window;
		std::cout << "EE > __UPDATE__\n";

		glClearColor(0.2f, 0.4f, 0.4f, 0.5f);
		
		while (!this->pWindowEngine.closed()) {
			this->pWindowEngine.clear();
			render();
			this->pWindowEngine.update();
			update();
		}
		std::cout << "EE > __UNLOAD__\n";
	}
	void Exodo::setFullScreen(bool isFullScreen, bool isWindowed = false)
	{
		this->isFullScreen = isFullScreen;
		this->isWindowed = isWindowed;
	}
	
		//destructor
	Exodo::~Exodo() {
		//finish
		std::cout << "EE > __FINISH__\n";
		unload();

		this->pWindowEngine.terminate();
	}

}

