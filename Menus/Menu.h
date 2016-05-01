#ifndef MENU_H
#define MENU_H

#include "../Shaders/ModelManager.h"

//********************************* CONSTANTS *********************************
 struct Cursor {
	 GLuint t;
	 int id;
 };
//********************************* INITIALIZATION *********************************

class Menu   {
	public: 
	Menu::		Menu();
	virtual void Menu::		init(Menu *screen);
	void Menu::		setBackground(GLuint id);
	void Menu::		addText(string s);
	void Menu::		addCursor(int id, int x, int y);
	static void Menu::	createCursor(GLuint t, int i);

	void Menu::addFlow(int menuIndex);	
	virtual void Menu::setFlow(int menuIndex);	
	virtual int Menu::getFlow();

	virtual void Menu::	cursorLR(int i);	
	virtual void Menu::	cursorUD(int i);
	virtual void Menu::	menuExit(){abort = true;}
		
	virtual void Menu::	enter(){affirm = true;}
	virtual void Menu::	reset();
	virtual void Menu::	quit(){abort = true;}



	
	virtual void Menu::		refresh();
	virtual void Menu::		refresh(int ind);
	void Menu::			rapidUpdate();


//********************************* DRAW *********************************

	
	virtual void Menu::	drawText();	
	virtual void Menu::	drawCursor();
	virtual void Menu::	drawIcons();
	virtual void Menu::	drawBackground ();


//********************************* MEMBER FUNCTIONS *********************************
	bool Menu::isDone(){return abort;};
	void Menu::setTimeOut(int to){timeOut = to;};
	virtual int Menu::getCategory(){return 0;}
//********************************* MEMBERS *********************************

	//MenuType type;
	string name;
	int menuID;
	int parent;
	//MenuType parent;
	//vector <DisplayItem> items;
	vector <string> text;
	vector <int> flows;
	XZI cursor;
	int cursorID;
	GLuint backgroundT;

	bool abort, affirm, update; 
	bool overlay, preview, fixed, backdrop;
	int index, maxIndex;
	int parentIndex;
	int lineH;
	int lineW;
	int timeOut;
	int time;
	static vector <Cursor> cursors;

protected:

};
#endif