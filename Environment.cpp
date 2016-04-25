//********************************* INITIALIZATION *********************************
#include "Environment.h"
Environment::Environment(){}	// dummy constructor

// Actual init - create actors
void Environment::init(){	
	//initSky();
	initFog(true);		// create fog	 
}

void Environment::	initSky(){
	getSkyColour();
}

void Environment::initFog(bool init){
	G->fog = init;	
	//fogColor[0] = 0.18; fogColor[1] = 0.75;
	//fogColor[2] = 1; fogColor[3] = 1;
	fogColor[0] = 0.5; fogColor[1] = 1;
	fogColor[2] = 1; fogColor[3] = 1;
	targetFog = 1;
	//M->fogD = FOG_D;	
	//M->adjustFog(0);
	targetFogD = 500;
	targetFogS = 150;
	if (G->fog) glEnable(GL_FOG);				//enable
	glClearColor(0, 0, 0, 1.0);		//initialise background color

	glFogi(GL_FOG_MODE, GL_LINEAR);			//linear mode?
	glHint(GL_FOG_HINT, GL_DONT_CARE);		//???

	glFogfv(GL_FOG_COLOR, fogColor);		
	glFogf(GL_FOG_START, 0);				//fog start <- follow the user 
	glFogf(GL_FOG_END, 1000);			//fog end
	//glFogi(GL_FOG_COORD_SRC, GL_FOG_COORDINATE);
	//glFogCoordf(5);
	glFogi(GL_FOG_COORD_SRC, GL_FRAGMENT_DEPTH);//?
	//*/
}




//********************************* CYCLE UPDATES *********************************


// AI
void Environment::rapidUpdate(float aiDelta){
	
	getSkyColour();
}




//********************************* VIEW FUNCTIONS *********************************

const glm::vec3 SkyTimeColour[] = { glm::vec3(0, 0, 0),  glm::vec3(0, 0.1, 0.12),  glm::vec3(0.1, 0.25, 0.3),  glm::vec3(0.3, 0.45, 0.5),  
									glm::vec3(0.4, 0.65, 0.75),  glm::vec3(0.4, 0.85, 0.9),  glm::vec3(0.45, 0.90, 0.95),  glm::vec3(0.5, 1, 1),
									glm::vec3(0.5, 1, 1),  glm::vec3(0.5, 1, 1),  glm::vec3(0.5, 1, 1),  glm::vec3(0.5, 1, 1),
									 glm::vec3(0.5, 1, 1), glm::vec3(0.5, 1, 1),  glm::vec3(0.5, 1, 1),  glm::vec3(0.45, 0.90, 0.95),
									glm::vec3(0.4, 0.85, 0.9),  glm::vec3(0.4, 0.65, 0.75),  glm::vec3(0.3, 0.55, 0.65),  glm::vec3(0.3, 0.45, 0.5),
									glm::vec3(0.2, 0.2, 0.2),  glm::vec3(0.2, 0.25, 0.3),  glm::vec3(0.2, 0.2, 0.2),  glm::vec3(0.1, 0.1, 0.1)  };

void Environment::	getSkyColour(){
	float r, g, b;
	int h1 = G->hours; 	int h2;
	if (h1 == 23) h2 = 0; 
	else h2 = h1 + 1; 
	float m = (G->minutes % 60 ) + G->slowTick * 0.125; //replace
	m = m/60 ;

	r = SkyTimeColour[h1].r - SkyTimeColour[h2].r;  
	r = SkyTimeColour[h1].r - r*m;
	g = SkyTimeColour[h1].g - SkyTimeColour[h2].g;  
	g = SkyTimeColour[h1].g - g*m;
	b = SkyTimeColour[h1].b - SkyTimeColour[h2].b;  
	b = SkyTimeColour[h1].b - b*m;
	skyColour.r = r;	skyColour.g = g;  skyColour.b = b;  
	fogColor[0] = skyColour.r;	fogColor[1] = skyColour.g; fogColor[2] = skyColour.b; //fogColor[3] = 1;	
}

// FOG UPDATE
void Environment::refreshView(){

	glClearColor(skyColour.r, skyColour.g, skyColour.b, 1);		//background
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_START, targetFogS);
	
}

