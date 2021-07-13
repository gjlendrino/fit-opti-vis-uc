#ifndef interface_I_Image
#define interface_I_Image
#include "../datatypes.h"

class I_Image {
public:

	virtual void get_image(imageData &data)=0;
	virtual ~I_Image();
};



#endif