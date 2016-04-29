//********************************* INITIALIZATION *********************************
#include "MenuLoader.h"

void MenuLoader::registerRootMenu(Menu * m){
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
				if (s == "Menu" && a) {
					s = getText(a->name());
					if (s == "filename"){
						s = getText(a->value());
						menuFiles.push_back(s);
					}
				}
			}
		}
		loadMenu(0);
	}catch(...){
		cout << "Menu did not load properly.";
	}
}//*/



void MenuLoader::loadMenu(int i){
	if (i < menuFiles.size()){
		rapidxml::file<> xmlFile(menuFiles[i].c_str()); // Default template is char
		rapidxml::xml_document<> doc;
		try {
			doc.parse<0>(xmlFile.data());
			rapidxml::xml_node<> *list = doc.first_node();
			rapidxml::xml_node<> *n;
			rapidxml::xml_attribute<> *a;
			string s = getText(list->name());
			if (s == "Menu"){ 
				for (a = list->first_attribute(); a; a = a->next_attribute()){
					s = getText(a->name());	
					cout << getText(a->name()) << endl;
				}
			}
		}catch(...){
			cout << "Menu did not load properly.";
		}
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