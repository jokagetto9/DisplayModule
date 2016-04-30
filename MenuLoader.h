#ifndef MENULOADER_H
#define MENULOADER_H
#include "Menus/Menu.h"
#include "../Utility/MCommand.h"

//********************************* CONSTANTS *********************************

//********************************* INITIALIZATION *********************************

class MenuLoader  {

public: 
	void MenuLoader::registerRoot(MenuCommand * m);


	void MenuLoader::loadList();
	void MenuLoader::loadMenuTree(int i);
	void MenuLoader::loadMenu(int i, rapidxml::xml_node<> * node);

	void MenuLoader::printList();
	void MenuLoader::printMenu(int i);


	string MenuLoader::getText(char * c);
	int MenuLoader::getInt(char * c);
private:
	vector <string> menuFiles;		
	vector <MenuCommand *> rMenus;

};
#endif