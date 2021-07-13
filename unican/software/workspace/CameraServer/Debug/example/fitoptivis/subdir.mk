################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../example/fitoptivis/main.cpp \
../example/fitoptivis/systemMainTasks.cpp 

OBJS += \
./example/fitoptivis/main.o \
./example/fitoptivis/systemMainTasks.o 

CPP_DEPS += \
./example/fitoptivis/main.d \
./example/fitoptivis/systemMainTasks.d 


# Each subdirectory must supply rules for building sources it contributes
example/fitoptivis/%.o: ../example/fitoptivis/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\RIE\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include\opencv4" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


