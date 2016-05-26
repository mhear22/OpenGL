
#include "header.h"
#include "DrawTool.h"
#include "Shader.h"

using namespace std::chrono;

class Game
{
public:
	Game();
	GLuint Program;
private:
	void Draw();
	
	DrawTool* drawTool;

	class Mouse
	{
	public:
		void static Clicked(GLFWwindow* window,int button, int action, int mods);
		void static Moved(GLFWwindow* window, double x, double y);
		double static mouseX;
		double static mouseY;
	};

	class Keyboard
	{
	public:
		void static KeyPress(GLFWwindow*,int,int, int, int);
	private:
		unsigned char static keys[256];
	};
};