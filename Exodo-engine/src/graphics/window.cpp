#include "window.h"
#include "..\input\input.h";

namespace ExodoEngine {
	namespace graphics {


		Window::Window()
		{
		}
		
		Window::Window(const char *name, int width, int height) {

			pName = name;
			pWidth = width;
			pHeight = height;

			if (!init())
				glfwTerminate();
		}

		void Window::render(const char *name, int width, int height) {
			Window::pName = name;
			Window::pWidth = width;
			Window::pHeight = height;

			if (!init())
				glfwTerminate();
		}


		void Window::setFullScreen(bool is, bool isWindowed)
		{
			this->isFullScreen = is;
			this->isWindowed = isWindowed;
		}

		bool Window::init() {

			if (!glfwInit()) {
				std::cout << "Error al crear GL Window";
				return false;
			}

			GLFWmonitor* monitor = glfwGetPrimaryMonitor();

			//glfwGetPrimaryMonitor()
			if (this->isFullScreen) {
				const GLFWvidmode * mode = glfwGetVideoMode(monitor );

				pWidth = mode->width;
				pHeight = mode->height;

			}
			if (this->isWindowed) {
				monitor = NULL;
			}

			pWindow = glfwCreateWindow(pWidth, pHeight, pName, monitor, NULL);
			if (!pWindow) {
				std::cout << "No se pudo completar esta operación";
				return false;
			}

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0, pWidth, pHeight, 0, 0, 1);

			glEnable(GL_DEPTH_TEST);
			glClearDepth(1.0f);
			glfwWindowHint(GLFW_SAMPLES, 4);
			glDepthFunc(GL_LEQUAL);
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
			glLineWidth(2.0f);

			glfwSwapInterval(1);


			glfwMakeContextCurrent(pWindow);
			glfwSetWindowUserPointer(pWindow, this);
			glfwSetWindowSizeCallback(pWindow, window_resize);
			glfwSetKeyCallback(pWindow, input::Input::key_callback );
			glfwSetMouseButtonCallback(pWindow, input::Input::mouse_button_callback);
			glfwSetCursorPosCallback(pWindow, input::Input::cursor_position_callback);
			glfwSetJoystickCallback(input::Input::joystick_callback);
			return true;
		}

	
		bool Window::closed() const {

			return glfwWindowShouldClose(pWindow) == 1;
		}

		void Window::terminate() const {
			
			 glfwTerminate();

		}

		void Window::update() {

			input::Input::joy_button();
			
			//Loop events
			glfwPollEvents();
			glfwGetFramebufferSize(pWindow, &pWidth, &pHeight);
			glfwSwapBuffers(pWindow);
		}

		void window_resize(GLFWwindow * window, int width, int height)
		{	
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			float aspect = float(win->pWidth) / win->pHeight;
			reshape_scene(window,width, height, aspect);
		}

		void reshape_scene(GLFWwindow * window, int width, int height, float aspect)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			int w = height * aspect;          
			int left = (width - w) / 2;
			std::cout << w;

			glViewport(left, 0, w, height);      
			glMatrixMode(GL_MODELVIEW);

		}


		void Window::clear() const
		{
			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		}

		//Destruct
		Window::~Window() {
			glfwTerminate();

		}


	}
}