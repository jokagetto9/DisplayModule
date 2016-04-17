#ifndef StackManager_H
#define StackManager_H

#include "../System/InputManager.h"
#include "./Base/BaseStackManager.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class StackManager : public BaseStackManager{
public:
	StackManager::StackManager();
	// Constructor
	
//********************************* LOADING *********************************
		

//********************************* SAVING *********************************

//********************************* UPDATES *********************************
	
	void StackManager::	update(InputManager &input);	
	
	
//********************************* DRAW *********************************

//************************************************** MEMBERS ***************************************************



//********************************* MEMBER FUNCTIONS *********************************

};
#endif
