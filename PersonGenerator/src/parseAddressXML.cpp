#include "CommonInclude.h"
#define NUMBER_OF_ADDRESSES 316

using namespace rapidxml;
using namespace std;

vector<string> parseAddressXML(const string& fileName) {
	xml_document<> doc;
	xml_node<>* root_node;
	// Read the xml file into a vector
	ifstream theFile(fileName);
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("ListOfAddresses");
	vector<string> Addresses(4 * NUMBER_OF_ADDRESSES);
	int i = 0;
	// Iterate over the Addresses
	for (xml_node<>* FullAddress_node = root_node->first_node("FullAddress"); FullAddress_node; FullAddress_node = FullAddress_node->next_sibling())
	{
		//Define nodes for each data type
		xml_node<>* address_node = FullAddress_node->first_node("address");
		xml_node<>* city_node = FullAddress_node->first_node("city");
		xml_node<>* state_node = FullAddress_node->first_node("state");
		xml_node<>* zip_node = FullAddress_node->first_node("zip");

		//output to console
		//cout << "Address:\t" << address_node->value() << endl;
		//cout << "City:\t\t" << city_node->value() << endl;
		//cout << "State:\t\t" << state_node->value() << endl;
		//cout << "Zip Code:\t" << zip_node->value() << endl;

		//store in vector
		Addresses.at(i) = address_node->value();
		Addresses.at(i + NUMBER_OF_ADDRESSES) = city_node->value();
		Addresses.at(i + 2 * (NUMBER_OF_ADDRESSES)) = state_node->value();
		Addresses.at(i + 3 * (NUMBER_OF_ADDRESSES)) = zip_node->value();
		//cout << Addresses.at(i) << endl;

		i++;
		//cout << endl;
	}
	//return Vector
	theFile.close();
	return Addresses;
}