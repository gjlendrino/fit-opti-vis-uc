#ifndef fitoptivis_component_Camera
#define fitoptivis_component_Camera
#include "../fitoptivis_base.h"

class Camera:virtual public RIEComponent,virtual public I_Image{
public:

	//Subcomponents

	//Qualities

	//Parameters

	//Monitors

	//Required interfaces


	//Reconfiguration functions
	virtual void run();
	virtual bool stop();
	virtual bool isStopped();


	virtual bool assignSetPoint(string s);
	virtual string readQuality();

	cv::VideoCapture cap;
	cv::Mat image;

	//Provided services
	virtual void get_image(imageData &data);

	//Constructor and destructor
	Camera();
	Camera(string name);
	virtual ~Camera();

private:
	void linkComponent();
};

#endif
