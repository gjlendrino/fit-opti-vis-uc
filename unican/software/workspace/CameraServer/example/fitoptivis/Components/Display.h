#ifndef fitoptivis_component_Display
#define fitoptivis_component_Display
#include "../fitoptivis_base.h"

class Display:virtual public RIEComponent{
public:

	//Subcomponents

	//Qualities

	//Parameters

	//Monitors

	//Required interfaces

	RIEInterface<I_Image> ir1;


	//Reconfiguration functions
	virtual void run();
	virtual bool stop();
	virtual bool isStopped();


	virtual bool assignSetPoint(string s);
	virtual string readQuality();

	void execFunc();
	imageData image;
	bool  isActive;
	mutex DisplayActive;
	bool stateDisplayWorking;

	thread *hilo;
	thread::native_handle_type hilo_native;
	cv::Mat img;


	//Provided services

	//Constructor and destructor
	Display();
	Display(string name);
	virtual ~Display();

private:
	void linkComponent();
};

#endif
