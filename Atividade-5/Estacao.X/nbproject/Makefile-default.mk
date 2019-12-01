#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ADConverter.cpp Estacao.cpp BMP280.cpp LDR.cpp LCD.cpp DHT11.cpp EEPROM.cpp GPIO.cpp GPIO_Port.cpp extint.cpp TWIMaster.cpp TWISlave.cpp SPI.cpp Timer.cpp Timeout.cpp Singleton.cpp UART.cpp main.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ADConverter.o ${OBJECTDIR}/Estacao.o ${OBJECTDIR}/BMP280.o ${OBJECTDIR}/LDR.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/DHT11.o ${OBJECTDIR}/EEPROM.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/GPIO_Port.o ${OBJECTDIR}/extint.o ${OBJECTDIR}/TWIMaster.o ${OBJECTDIR}/TWISlave.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/Timer.o ${OBJECTDIR}/Timeout.o ${OBJECTDIR}/Singleton.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ADConverter.o.d ${OBJECTDIR}/Estacao.o.d ${OBJECTDIR}/BMP280.o.d ${OBJECTDIR}/LDR.o.d ${OBJECTDIR}/LCD.o.d ${OBJECTDIR}/DHT11.o.d ${OBJECTDIR}/EEPROM.o.d ${OBJECTDIR}/GPIO.o.d ${OBJECTDIR}/GPIO_Port.o.d ${OBJECTDIR}/extint.o.d ${OBJECTDIR}/TWIMaster.o.d ${OBJECTDIR}/TWISlave.o.d ${OBJECTDIR}/SPI.o.d ${OBJECTDIR}/Timer.o.d ${OBJECTDIR}/Timeout.o.d ${OBJECTDIR}/Singleton.o.d ${OBJECTDIR}/UART.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ADConverter.o ${OBJECTDIR}/Estacao.o ${OBJECTDIR}/BMP280.o ${OBJECTDIR}/LDR.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/DHT11.o ${OBJECTDIR}/EEPROM.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/GPIO_Port.o ${OBJECTDIR}/extint.o ${OBJECTDIR}/TWIMaster.o ${OBJECTDIR}/TWISlave.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/Timer.o ${OBJECTDIR}/Timeout.o ${OBJECTDIR}/Singleton.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=ADConverter.cpp Estacao.cpp BMP280.cpp LDR.cpp LCD.cpp DHT11.cpp EEPROM.cpp GPIO.cpp GPIO_Port.cpp extint.cpp TWIMaster.cpp TWISlave.cpp SPI.cpp Timer.cpp Timeout.cpp Singleton.cpp UART.cpp main.cpp


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
Device=ATmega2560
ProjectDir=/home/felipe/ifsc/ste/Atividade-5/Estacao.X
ConfName=default
ImagePath=dist/default/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ImageDir=dist/default/${IMAGE_TYPE}
ImageName=Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [avrdude -c avrispmkII -P /dev/ttyUSB0 -D -p ${Device} -U flash:w:${ImagePath}:i]"
	@avrdude -c avrispmkII -P /dev/ttyUSB0 -D -p ${Device} -U flash:w:${ImagePath}:i
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=ATmega2560
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ADConverter.o: ADConverter.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADConverter.o.d 
	@${RM} ${OBJECTDIR}/ADConverter.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/ADConverter.o.d" -MT "${OBJECTDIR}/ADConverter.o.d" -MT ${OBJECTDIR}/ADConverter.o  -o ${OBJECTDIR}/ADConverter.o ADConverter.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Estacao.o: Estacao.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Estacao.o.d 
	@${RM} ${OBJECTDIR}/Estacao.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Estacao.o.d" -MT "${OBJECTDIR}/Estacao.o.d" -MT ${OBJECTDIR}/Estacao.o  -o ${OBJECTDIR}/Estacao.o Estacao.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/BMP280.o: BMP280.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BMP280.o.d 
	@${RM} ${OBJECTDIR}/BMP280.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/BMP280.o.d" -MT "${OBJECTDIR}/BMP280.o.d" -MT ${OBJECTDIR}/BMP280.o  -o ${OBJECTDIR}/BMP280.o BMP280.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/LDR.o: LDR.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LDR.o.d 
	@${RM} ${OBJECTDIR}/LDR.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/LDR.o.d" -MT "${OBJECTDIR}/LDR.o.d" -MT ${OBJECTDIR}/LDR.o  -o ${OBJECTDIR}/LDR.o LDR.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/LCD.o: LCD.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/LCD.o.d" -MT "${OBJECTDIR}/LCD.o.d" -MT ${OBJECTDIR}/LCD.o  -o ${OBJECTDIR}/LCD.o LCD.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/DHT11.o: DHT11.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DHT11.o.d 
	@${RM} ${OBJECTDIR}/DHT11.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/DHT11.o.d" -MT "${OBJECTDIR}/DHT11.o.d" -MT ${OBJECTDIR}/DHT11.o  -o ${OBJECTDIR}/DHT11.o DHT11.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/EEPROM.o: EEPROM.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM.o.d 
	@${RM} ${OBJECTDIR}/EEPROM.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/EEPROM.o.d" -MT "${OBJECTDIR}/EEPROM.o.d" -MT ${OBJECTDIR}/EEPROM.o  -o ${OBJECTDIR}/EEPROM.o EEPROM.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/GPIO.o: GPIO.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/GPIO.o.d" -MT "${OBJECTDIR}/GPIO.o.d" -MT ${OBJECTDIR}/GPIO.o  -o ${OBJECTDIR}/GPIO.o GPIO.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/GPIO_Port.o: GPIO_Port.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO_Port.o.d 
	@${RM} ${OBJECTDIR}/GPIO_Port.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/GPIO_Port.o.d" -MT "${OBJECTDIR}/GPIO_Port.o.d" -MT ${OBJECTDIR}/GPIO_Port.o  -o ${OBJECTDIR}/GPIO_Port.o GPIO_Port.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/extint.o: extint.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/extint.o.d 
	@${RM} ${OBJECTDIR}/extint.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/extint.o.d" -MT "${OBJECTDIR}/extint.o.d" -MT ${OBJECTDIR}/extint.o  -o ${OBJECTDIR}/extint.o extint.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/TWIMaster.o: TWIMaster.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWIMaster.o.d 
	@${RM} ${OBJECTDIR}/TWIMaster.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/TWIMaster.o.d" -MT "${OBJECTDIR}/TWIMaster.o.d" -MT ${OBJECTDIR}/TWIMaster.o  -o ${OBJECTDIR}/TWIMaster.o TWIMaster.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/TWISlave.o: TWISlave.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWISlave.o.d 
	@${RM} ${OBJECTDIR}/TWISlave.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/TWISlave.o.d" -MT "${OBJECTDIR}/TWISlave.o.d" -MT ${OBJECTDIR}/TWISlave.o  -o ${OBJECTDIR}/TWISlave.o TWISlave.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/SPI.o: SPI.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/SPI.o.d" -MT "${OBJECTDIR}/SPI.o.d" -MT ${OBJECTDIR}/SPI.o  -o ${OBJECTDIR}/SPI.o SPI.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timer.o: Timer.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer.o.d 
	@${RM} ${OBJECTDIR}/Timer.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timer.o.d" -MT "${OBJECTDIR}/Timer.o.d" -MT ${OBJECTDIR}/Timer.o  -o ${OBJECTDIR}/Timer.o Timer.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timeout.o: Timeout.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timeout.o.d 
	@${RM} ${OBJECTDIR}/Timeout.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timeout.o.d" -MT "${OBJECTDIR}/Timeout.o.d" -MT ${OBJECTDIR}/Timeout.o  -o ${OBJECTDIR}/Timeout.o Timeout.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Singleton.o: Singleton.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Singleton.o.d 
	@${RM} ${OBJECTDIR}/Singleton.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Singleton.o.d" -MT "${OBJECTDIR}/Singleton.o.d" -MT ${OBJECTDIR}/Singleton.o  -o ${OBJECTDIR}/Singleton.o Singleton.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/UART.o: UART.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/UART.o.d" -MT "${OBJECTDIR}/UART.o.d" -MT ${OBJECTDIR}/UART.o  -o ${OBJECTDIR}/UART.o UART.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/ADConverter.o: ADConverter.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADConverter.o.d 
	@${RM} ${OBJECTDIR}/ADConverter.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/ADConverter.o.d" -MT "${OBJECTDIR}/ADConverter.o.d" -MT ${OBJECTDIR}/ADConverter.o  -o ${OBJECTDIR}/ADConverter.o ADConverter.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Estacao.o: Estacao.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Estacao.o.d 
	@${RM} ${OBJECTDIR}/Estacao.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Estacao.o.d" -MT "${OBJECTDIR}/Estacao.o.d" -MT ${OBJECTDIR}/Estacao.o  -o ${OBJECTDIR}/Estacao.o Estacao.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/BMP280.o: BMP280.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BMP280.o.d 
	@${RM} ${OBJECTDIR}/BMP280.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/BMP280.o.d" -MT "${OBJECTDIR}/BMP280.o.d" -MT ${OBJECTDIR}/BMP280.o  -o ${OBJECTDIR}/BMP280.o BMP280.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/LDR.o: LDR.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LDR.o.d 
	@${RM} ${OBJECTDIR}/LDR.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/LDR.o.d" -MT "${OBJECTDIR}/LDR.o.d" -MT ${OBJECTDIR}/LDR.o  -o ${OBJECTDIR}/LDR.o LDR.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/LCD.o: LCD.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/LCD.o.d" -MT "${OBJECTDIR}/LCD.o.d" -MT ${OBJECTDIR}/LCD.o  -o ${OBJECTDIR}/LCD.o LCD.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/DHT11.o: DHT11.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DHT11.o.d 
	@${RM} ${OBJECTDIR}/DHT11.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/DHT11.o.d" -MT "${OBJECTDIR}/DHT11.o.d" -MT ${OBJECTDIR}/DHT11.o  -o ${OBJECTDIR}/DHT11.o DHT11.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/EEPROM.o: EEPROM.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM.o.d 
	@${RM} ${OBJECTDIR}/EEPROM.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/EEPROM.o.d" -MT "${OBJECTDIR}/EEPROM.o.d" -MT ${OBJECTDIR}/EEPROM.o  -o ${OBJECTDIR}/EEPROM.o EEPROM.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/GPIO.o: GPIO.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/GPIO.o.d" -MT "${OBJECTDIR}/GPIO.o.d" -MT ${OBJECTDIR}/GPIO.o  -o ${OBJECTDIR}/GPIO.o GPIO.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/GPIO_Port.o: GPIO_Port.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO_Port.o.d 
	@${RM} ${OBJECTDIR}/GPIO_Port.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/GPIO_Port.o.d" -MT "${OBJECTDIR}/GPIO_Port.o.d" -MT ${OBJECTDIR}/GPIO_Port.o  -o ${OBJECTDIR}/GPIO_Port.o GPIO_Port.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/extint.o: extint.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/extint.o.d 
	@${RM} ${OBJECTDIR}/extint.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/extint.o.d" -MT "${OBJECTDIR}/extint.o.d" -MT ${OBJECTDIR}/extint.o  -o ${OBJECTDIR}/extint.o extint.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/TWIMaster.o: TWIMaster.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWIMaster.o.d 
	@${RM} ${OBJECTDIR}/TWIMaster.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/TWIMaster.o.d" -MT "${OBJECTDIR}/TWIMaster.o.d" -MT ${OBJECTDIR}/TWIMaster.o  -o ${OBJECTDIR}/TWIMaster.o TWIMaster.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/TWISlave.o: TWISlave.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWISlave.o.d 
	@${RM} ${OBJECTDIR}/TWISlave.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/TWISlave.o.d" -MT "${OBJECTDIR}/TWISlave.o.d" -MT ${OBJECTDIR}/TWISlave.o  -o ${OBJECTDIR}/TWISlave.o TWISlave.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/SPI.o: SPI.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/SPI.o.d" -MT "${OBJECTDIR}/SPI.o.d" -MT ${OBJECTDIR}/SPI.o  -o ${OBJECTDIR}/SPI.o SPI.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timer.o: Timer.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer.o.d 
	@${RM} ${OBJECTDIR}/Timer.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timer.o.d" -MT "${OBJECTDIR}/Timer.o.d" -MT ${OBJECTDIR}/Timer.o  -o ${OBJECTDIR}/Timer.o Timer.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timeout.o: Timeout.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timeout.o.d 
	@${RM} ${OBJECTDIR}/Timeout.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timeout.o.d" -MT "${OBJECTDIR}/Timeout.o.d" -MT ${OBJECTDIR}/Timeout.o  -o ${OBJECTDIR}/Timeout.o Timeout.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Singleton.o: Singleton.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Singleton.o.d 
	@${RM} ${OBJECTDIR}/Singleton.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Singleton.o.d" -MT "${OBJECTDIR}/Singleton.o.d" -MT ${OBJECTDIR}/Singleton.o  -o ${OBJECTDIR}/Singleton.o Singleton.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/UART.o: UART.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/UART.o.d" -MT "${OBJECTDIR}/UART.o.d" -MT ${OBJECTDIR}/UART.o  -o ${OBJECTDIR}/UART.o UART.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=atmega2560  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=atmega2560  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Estacao.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
