#pragma once
#include "Module.h"
#include <list>
#include <string>
#include <vector>
#include "Globals.h"
#include "Timer.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleSceneIntro.h"
#include "ModuleRenderer3D.h"
#include "ModuleCamera3D.h"
#include "ModuleUI.h"
#include "ModuleFBXLoader.h"
#include "ModuleMaterials.h"
#include "JsonParsing.h"
#include "ModuleFileSystem.h"

// USAR PARA STL: https://github.com/karansaxena/STL_Cheat_Sheets

#define CONFIG_FILENAME	"config.json"
#define APPLICATION_NAME "EdgeEngine"
#define ORGANIZATION_NAME "UPC"

class Application
{
public:
	ModuleWindow* window;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleSceneIntro* scene_intro;
	ModuleRenderer3D* renderer3D;
	ModuleCamera3D* camera;
	ModuleUI* ui;
	ModuleFBXLoader* loaderModels;
	ModuleMaterial* materialImport;
	

	ModuleFileSystem* fs;

	JsonParsing jsonFile;

	bool debug;
	bool pause;
	bool back_to_original;

	

private:

	std::list<Module*> list_modules;
	Timer	ms_timer;
	
	float	dt;

	bool saveRequest;
	bool loadRequest;

	bool saveSceneRequest = false;
	bool loadSceneRequest = false;
	
public:

	Application();
	~Application();

	bool Init();
	bool Update();
	bool CleanUp();

	void RequestBrowser(const char* string);

	inline const char* GetAppName() const { return APPLICATION_NAME; }
	inline const char* GetOrganizationName() const { return ORGANIZATION_NAME; }

	inline void SaveConfigRequest() { saveRequest = true; }
	inline void LoadConfigRequest() { loadRequest = true; }
	inline void SaveSceneRequest() { saveSceneRequest = true; }
	inline void LoadSceneRequesst() { loadSceneRequest = true; }

	float Dt() const;

	void GetCPU(int& count, int& size);
	float GetRAM();
	void GetSDLVersion(int& major, int& minor, int& patch);
	void AddConsoleLogs(const char* log);
	
private:

	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();

	void SaveConfig();
	void LoadConfig();

	void SaveScene();
	void LoadScene();
};