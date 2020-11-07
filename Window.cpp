#include "All.h"
#include "Window.h"
#include <gl\glew.h>

	//Set Window Size
#define Default_Width (1920)
#define Default_Height (1007)

Window::Window(const char* name, int x, int y)
{
	handle = SDL_CreateWindow(name, x, y, Default_Width, Default_Height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
	if (handle == nullptr) {
		printf("Window Could not be Created");
		printf(SDL_GetError());
		SDL_ClearError();
		exit(EXIT_FAILURE);
	}
	context = SDL_GL_CreateContext(handle);
	if (context == NULL) {
		printf("Window Could not be Created");
		printf(SDL_GetError());
		SDL_ClearError();
		exit(EXIT_FAILURE);
	}
	Window::makeCurrent();
}
Window::Window(const char* name)
{
	handle = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Default_Width, Default_Height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
	if (handle == nullptr) {
		printf("Window Could not be Created");
		printf(SDL_GetError());
		SDL_ClearError();
		exit(EXIT_FAILURE);
	}
	context = SDL_GL_CreateContext(handle);
	if (context == NULL) {
		printf("Window Could not be Created");
		printf(SDL_GetError());
		SDL_ClearError();
		exit(EXIT_FAILURE);
	}
	Window::makeCurrent();
}
Window::Window()
{
	handle = SDL_CreateWindow("Unnamed Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Default_Width, Default_Height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
	if(handle == nullptr){
		printf("Window Could not be Created");
		printf(SDL_GetError());
		SDL_ClearError();
		exit(EXIT_FAILURE);
	}
	context = SDL_GL_CreateContext(handle);
	if (context == NULL) {
		printf("Window Could not be Created");
		printf(SDL_GetError());
		SDL_ClearError();
		exit(EXIT_FAILURE);
	}
	Window::makeCurrent();
}
Window::~Window()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(handle);

	handle = nullptr;
	context = nullptr;
}
/**
 *  \brief Make window the current openGL context
 *  \return 0 on success, 1 on a pointer being null
 */
int Window::makeCurrent()
{
	if (this == nullptr) { return 1; }
	if (handle == nullptr || context == NULL) { return 1; }
	if(SDL_GL_MakeCurrent(handle, context)  < 0)
	{
		checkError(__LINE__);
		return 2;
	}
	SDL_GL_SetSwapInterval(1);

	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		printf(__LINE__ + "Error Switching Context %s\n", glewGetErrorString(glewError));
		return 3;
	}
	return 0;
}
	//Set Window Position
void Window::setPos(int x, int y)
{
	SDL_SetWindowPosition(handle, x, y);
}