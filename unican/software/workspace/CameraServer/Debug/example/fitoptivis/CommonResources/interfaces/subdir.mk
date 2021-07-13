################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../example/fitoptivis/CommonResources/interfaces/I_Image.cpp \
../example/fitoptivis/CommonResources/interfaces/I_Image_Remote.cpp 

OBJS += \
./example/fitoptivis/CommonResources/interfaces/I_Image.o \
./example/fitoptivis/CommonResources/interfaces/I_Image_Remote.o 

CPP_DEPS += \
./example/fitoptivis/CommonResources/interfaces/I_Image.d \
./example/fitoptivis/CommonResources/interfaces/I_Image_Remote.d 


# Each subdirectory must supply rules for building sources it contributes
example/fitoptivis/CommonResources/interfaces/%.o: ../example/fitoptivis/CommonResources/interfaces/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\RIE\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include\opencv4" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


