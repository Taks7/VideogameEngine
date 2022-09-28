#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "SDL/include/SDL.h"
#include "ModuleWindow.h"
#include <vector>

class Application;
class UI;
class AboutMenu;

class ModuleUI : public Module
{
public:

	ModuleUI(bool start_enabled = true);

	// Destructor
	virtual ~ModuleUI();

	bool Init();
	bool PreUpdate(float dt);
	bool Update(float dt);
	bool PostUpdate(float dt);
	bool CleanUp();

	

public:
	//MENU THINGYS
	void MainMenu();
	bool fullscreen = false;
	bool Vsync = false;
	int screenWidth;
	int screenHeight;
	
	bool enableAboutMenu;

	AboutMenu* aboutMenu;
private:

	std::vector<UI*> menus;
};

#endif // __ModuleWindow_H__