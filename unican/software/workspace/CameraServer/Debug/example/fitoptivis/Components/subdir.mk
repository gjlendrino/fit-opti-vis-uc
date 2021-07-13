################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../example/fitoptivis/Components/Camera.cpp \
../example/fitoptivis/Components/Display.cpp \
../example/fitoptivis/Components/components.cpp \
../example/fitoptivis/Components/system.cpp 

OBJS += \
./example/fitoptivis/Components/Camera.o \
./example/fitoptivis/Components/Display.o \
./example/fitoptivis/Components/components.o \
./example/fitoptivis/Components/system.o 

CPP_DEPS += \
./example/fitoptivis/Components/Camera.d \
./example/fitoptivis/Components/Display.d \
./example/fitoptivis/Components/components.d \
./example/fitoptivis/Components/system.d 


# Each subdirectory must supply rules for building sources it contributes
example/fitoptivis/Components/%.o: ../example/fitoptivis/Components/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\RIE\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include\opencv4" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


