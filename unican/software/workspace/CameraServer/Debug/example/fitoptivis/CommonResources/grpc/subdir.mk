################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../example/fitoptivis/CommonResources/grpc/I_Image_grpc.grpc.pb.cc \
../example/fitoptivis/CommonResources/grpc/I_Image_grpc.pb.cc 

CC_DEPS += \
./example/fitoptivis/CommonResources/grpc/I_Image_grpc.grpc.pb.d \
./example/fitoptivis/CommonResources/grpc/I_Image_grpc.pb.d 

OBJS += \
./example/fitoptivis/CommonResources/grpc/I_Image_grpc.grpc.pb.o \
./example/fitoptivis/CommonResources/grpc/I_Image_grpc.pb.o 


# Each subdirectory must supply rules for building sources it contributes
example/fitoptivis/CommonResources/grpc/%.o: ../example/fitoptivis/CommonResources/grpc/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\RIE\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include" -I"C:\Users\Thales\Documents\fit-opti-vis\unican\software\soft\msys64\mingw64\include\opencv4" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


