#ifndef datatypes_imageData
#define datatypes_imageData

#include <iostream>
using namespace std;


class imageData {
public:

	int h;
	int w;
	int format;
	string data;

	virtual ~imageData(){};
	imageData(){};
};



#endif