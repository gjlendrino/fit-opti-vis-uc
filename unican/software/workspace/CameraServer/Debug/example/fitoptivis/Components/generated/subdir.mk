################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../example/fitoptivis/Components/generated/Camera_Remote.cpp \
../example/fitoptivis/Components/generated/Camera_RemoteServer.cpp \
../example/fitoptivis/Components/generated/component.cpp \
../example/fitoptivis/Components/generated/generatedComponent_server.cpp \
../example/fitoptivis/Components/generated/generatedDNS_server.cpp 

OBJS += \
./example/fitoptivis/Components/generated/Camera_Remote.o \
./example/fitoptivis/Components/generated/Camera_RemoteServer.o \
./example/fitoptivis/Components/generated/component.o \
./example/fitoptivis/Components/generated/generatedComponent_server.o \
./example/fitoptivis/Components/generated/generatedDNS_server.o 

CPP_DEPS += \
./example/fitoptivis/Components/generated/Camera_Remote.d \
./example/fitoptivis/Components/generated/Camera_RemoteServer.d \
./example/fitoptivis/Components/generated/component.d \
./example/fitoptivis/Components/generated/generatedComponent_server.d \
./example/fitoptivis/Components/generated/generatedDNS_server.d 


# Each subdirectory must supply rules for building sources it contributes
example/fitoptivis/Components/generated/%.o: ../example/fitoptivis/Components/generated/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\RIE\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include\opencv4" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


