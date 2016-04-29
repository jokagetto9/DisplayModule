#ifndef MENULOADER_H
#define MENULOADER_H
#include "Menus/Menu.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class MenuLoader  {

public: 
	void MenuLoader::registerRootMenu(Menu * m);


	void MenuLoader::loadList();
	void MenuLoader::loadMenu(int i);

	void MenuLoader::printList();
	void MenuLoader::printMenu(int i);


	string MenuLoader::getText(char * c);
private:
	vector <string> menuFiles;		
	vector <Menu *> rMenus;

};
#endif