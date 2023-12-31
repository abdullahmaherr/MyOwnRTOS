################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyRTOS/cortex_mx_os_porting.c \
../MyRTOS/rtos_fifo.c \
../MyRTOS/scheduler.c 

OBJS += \
./MyRTOS/cortex_mx_os_porting.o \
./MyRTOS/rtos_fifo.o \
./MyRTOS/scheduler.o 

C_DEPS += \
./MyRTOS/cortex_mx_os_porting.d \
./MyRTOS/rtos_fifo.d \
./MyRTOS/scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
MyRTOS/cortex_mx_os_porting.o: ../MyRTOS/cortex_mx_os_porting.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/MyRTOS/inc" -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/Drivers/inc" -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyRTOS/cortex_mx_os_porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MyRTOS/rtos_fifo.o: ../MyRTOS/rtos_fifo.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/MyRTOS/inc" -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/Drivers/inc" -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyRTOS/rtos_fifo.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MyRTOS/scheduler.o: ../MyRTOS/scheduler.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/MyRTOS/inc" -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/Drivers/inc" -I"C:/Users/abdullah/Desktop/MyOwnRTOS/MyOwnRTOS/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyRTOS/scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

