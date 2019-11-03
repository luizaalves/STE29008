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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=main.cpp UART.cpp GPIO.cpp GPIO_Port.cpp extint.cpp Singleton.cpp Timeout.cpp Timer.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/GPIO_Port.o ${OBJECTDIR}/extint.o ${OBJECTDIR}/Singleton.o ${OBJECTDIR}/Timeout.o ${OBJECTDIR}/Timer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/UART.o.d ${OBJECTDIR}/GPIO.o.d ${OBJECTDIR}/GPIO_Port.o.d ${OBJECTDIR}/extint.o.d ${OBJECTDIR}/Singleton.o.d ${OBJECTDIR}/Timeout.o.d ${OBJECTDIR}/Timer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/GPIO_Port.o ${OBJECTDIR}/extint.o ${OBJECTDIR}/Singleton.o ${OBJECTDIR}/Timeout.o ${OBJECTDIR}/Timer.o

# Source Files
SOURCEFILES=main.cpp UART.cpp GPIO.cpp GPIO_Port.cpp extint.cpp Singleton.cpp Timeout.cpp Timer.cpp


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
ProjectDir=/home/felipe/ifsc/ste/Atividade-4/adc_v1.X
ConfName=default
ImagePath=dist/default/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ImageDir=dist/default/${IMAGE_TYPE}
ImageName=adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
${OBJECTDIR}/main.o: main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/UART.o: UART.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/UART.o.d" -MT "${OBJECTDIR}/UART.o.d" -MT ${OBJECTDIR}/UART.o  -o ${OBJECTDIR}/UART.o UART.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
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
	
${OBJECTDIR}/Singleton.o: Singleton.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Singleton.o.d 
	@${RM} ${OBJECTDIR}/Singleton.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Singleton.o.d" -MT "${OBJECTDIR}/Singleton.o.d" -MT ${OBJECTDIR}/Singleton.o  -o ${OBJECTDIR}/Singleton.o Singleton.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timeout.o: Timeout.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timeout.o.d 
	@${RM} ${OBJECTDIR}/Timeout.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timeout.o.d" -MT "${OBJECTDIR}/Timeout.o.d" -MT ${OBJECTDIR}/Timeout.o  -o ${OBJECTDIR}/Timeout.o Timeout.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timer.o: Timer.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer.o.d 
	@${RM} ${OBJECTDIR}/Timer.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560" -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timer.o.d" -MT "${OBJECTDIR}/Timer.o.d" -MT ${OBJECTDIR}/Timer.o  -o ${OBJECTDIR}/Timer.o Timer.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/main.o: main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/UART.o: UART.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/UART.o.d" -MT "${OBJECTDIR}/UART.o.d" -MT ${OBJECTDIR}/UART.o  -o ${OBJECTDIR}/UART.o UART.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
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
	
${OBJECTDIR}/Singleton.o: Singleton.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Singleton.o.d 
	@${RM} ${OBJECTDIR}/Singleton.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Singleton.o.d" -MT "${OBJECTDIR}/Singleton.o.d" -MT ${OBJECTDIR}/Singleton.o  -o ${OBJECTDIR}/Singleton.o Singleton.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timeout.o: Timeout.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timeout.o.d 
	@${RM} ${OBJECTDIR}/Timeout.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timeout.o.d" -MT "${OBJECTDIR}/Timeout.o.d" -MT ${OBJECTDIR}/Timeout.o  -o ${OBJECTDIR}/Timeout.o Timeout.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Timer.o: Timer.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer.o.d 
	@${RM} ${OBJECTDIR}/Timer.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega2560  -I "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/include"  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000L -Wall -MD -MP -MF "${OBJECTDIR}/Timer.o.d" -MT "${OBJECTDIR}/Timer.o.d" -MT ${OBJECTDIR}/Timer.o  -o ${OBJECTDIR}/Timer.o Timer.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=atmega2560  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=atmega2560  -B "/opt/microchip/mplabx/v5.20/packs/Microchip/ATmega_DFP/2.0.12/gcc/dev/atmega2560"  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/adc_v1.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
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
