//********************************* INITIALIZATION *********************************
#include "MenuLoader.h"

void MenuLoader::registerRoot(StackCommand * m){
	if (m)
		rMenus.push_back(m);
}



void MenuLoader::loadList(){
    rapidxml::file<> xmlFile("menulist.xml"); // Default template is char
    rapidxml::xml_document<> doc;
	try {
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *list = doc.first_node();
		rapidxml::xml_node<> *n;
		rapidxml::xml_attribute<> *a;
		string s = getText(list->name());
		if (s == "MenuList"){ 
			for (n = list->first_node(); n; n = n->next_sibling()){
				s = getText(n->name());		
				a = n->first_attribute();
				if (s == "MenuFile" && a) {
					s = getText(a->name());
					if (s == "filename"){
						s = getText(a->value());
						menuFiles.push_back(s);
					}
				}
			}
		}
		loadMenuTree(0);
	}catch(...){
		cout << "Menu did not load properly.";
	}
}//*/

void MenuLoader::loadMenuTree(int i){
	if (i < menuFiles.size() && i < rMenus.size()){
		rapidxml::file<> xmlFile(menuFiles[i].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		try {
			doc.parse<0>(xmlFile.data());
			rapidxml::xml_node<> *list = doc.first_node();
			for (list = doc.first_node(); list; list = list->next_sibling())
				loadMenu(i, list);
		}catch(...){
			cout << "Menu [" << i << "] did not load properly.";
		}
	}
}

void MenuLoader::loadMenu(int i, rapidxml::xml_node<> * node){
	rapidxml::xml_node<> *n;
	rapidxml::xml_attribute<> *a;
	string s = getText(node->name());
	Menu menu;

	if (s == "Menu"){ 
		for (a = node->first_attribute(); a; a = a->next_attribute()){
			s = getText(a->name());	
			if (s == "name")
				menu.name = getText(a->value());					
			if (s == "timeout")
				menu.timeOut = getInt(a->value());	
		}
		for (n = node->first_node(); n; n = n->next_sibling()){
			s = getText(n->name());	
			if (s == "Background"){
				for (a = node->first_attribute(); a; a = a->next_attribute()){

				}
			}
		}
		rMenus[0]->addMenu(menu);
	}
	
}


void MenuLoader::printList(){
	for (int i = 0; i < menuFiles.size(); i++){
		cout << menuFiles[i] << endl;
	}
}

void MenuLoader::printMenu(int i){
	if (i < menuFiles.size()){


	}
}

string MenuLoader::getText(char * c){	
	stringstream ss; string s;
	ss << c;	 ss >> s;
	return s;
}


int MenuLoader::getInt(char * c){	
	stringstream ss; int i;
	ss << c;	 ss >> i;
	if (i < -10000)
		return 0;
	else 
		return i;
}