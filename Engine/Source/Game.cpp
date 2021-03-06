#include "Game.h"

Game::Game(Configuration* config)
{
	if(!glfwInit())
	{
		exit(0);
	}

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWmonitor* SelectedMonitor = NULL;
	
	ScreenWidth = 640;
	ScreenHeight = 480;
	
	if (config->Fullscreen)
	{
		int count;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		if (config->ScreenNumber > count)
			throw "bad";
		SelectedMonitor = monitors[config->ScreenNumber];
		const GLFWvidmode* mode = glfwGetVideoMode(SelectedMonitor);
		ScreenWidth = mode->width;
		ScreenHeight = mode->height;
	}
	currentWindow = glfwCreateWindow(ScreenWidth,ScreenHeight, "", SelectedMonitor, NULL);

	glfwMakeContextCurrent(currentWindow);
	
	auto ver = glGetString(GL_VERSION);
	printf("%s \n", ver);
	
#ifdef __APPLE__
#else
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		printf("%s \n", glewGetErrorString(err));
		exit(0);
	}
#endif
	
	std::vector<Shader> shaders;
	
	shaders.push_back(Shader(DefaultVertexShader , GL_VERTEX_SHADER));
	shaders.push_back(Shader(DefaultFragmentShader, GL_FRAGMENT_SHADER));
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);

	Program = glCreateProgram();
	for (int i = 0; i < shaders.size(); i++)
	{
		glAttachShader(Program, shaders[i].object());
	}
	glBindAttribLocation(Program, 1, "vert");
	
	
	float aspect = ((ScreenWidth + 0.0f) /(ScreenHeight + 0.0f));
	
	glLinkProgram(Program);
	
	glUseProgram(Program);
	
	cam = new Camera(Program, aspect);
	drawTool = new DrawTool(Program);
	input = new Input(currentWindow,cam);
	container = new ModelContainer(drawTool);
	
	glUseProgram(0);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	glfwSetKeyCallback(currentWindow, Input::KeyPress);
	glfwSetInputMode(currentWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(currentWindow, 0, 0);
	glfwSetMouseButtonCallback(currentWindow, Input::Click);
	glfwSetCursorPosCallback(currentWindow, Input::Move);
	
	
	//char location[] = "../Models/box.obj";
	//container->AddModel(new FileModel(location));
	container->AddModel(new TestModel());
	//container->AddModel(new SkyboxModel());
	
	
}

void Game::Run()
{
	if(currentWindow == nullptr)
	{
		throw "Null Pointer Exception";
	}
	
	container->Load();
	
	time = new TimeMonitor;
	
	while (!glfwWindowShouldClose(currentWindow))
	{
		Game::Draw();
		glfwSwapBuffers(currentWindow);
		glfwPollEvents();
	}
	
	glfwTerminate();
}

void Game::Draw()
{
	float tick = time->Tick();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(Program);
	input->Draw(tick);
	cam->draw();
	container->Draw();
	glUseProgram(0);
}
