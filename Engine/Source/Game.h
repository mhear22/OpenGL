#pragma once
#include "header.h"
#include "DrawTool.h"
#include "Shader.h"
#include "Camera.h"
#include "Input.h"
#include "ModelBase.h"
#include "ModelContainer.h"
#include "TestModel.h"
#include "SkyboxModel.h"
#include "FileModel.h"
#include "Configuration.h"
#include "TimeMonitor.h"

using namespace std::chrono;

class Game
{
public:
	Game(Configuration* config);
	void Run();
	GLuint Program;
private:
	void Draw();
	
	int ScreenHeight;
	int ScreenWidth;
	GLFWwindow* currentWindow;;
	DrawTool* drawTool;
	Camera* cam;
	Input* input;
	ModelContainer* container;
	TimeMonitor* time;
};
