#include "DataLoader.h"

void readFile (string filePath){
	ifstream file;
	file.open (filePath);
	rapidxml::xml_document<> doc;

	vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>( ));

	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]);

	cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
	cout << "Value of my first node is: " << doc.first_node()->value() << "\n";


	file.close();
}