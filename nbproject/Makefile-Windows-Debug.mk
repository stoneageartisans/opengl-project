#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_TDM-Windows
CND_DLIB_EXT=dll
CND_CONF=Windows-Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/application.o \
	${OBJECTDIR}/source/logger.o \
	${OBJECTDIR}/source/main.o \
	${OBJECTDIR}/source/shader.o


# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../libraries/glad-core-3.3/lib -L../../../libraries/glfw-3.2.1.bin.WIN64/lib-mingw-w64 -lglad -lglfw3dll -lopengl32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk start-win32.exe

start-win32.exe: ${OBJECTFILES}
	${LINK.cc} -o start-win32 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/source/application.o: source/application.cpp
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/application.o source/application.cpp

${OBJECTDIR}/source/logger.o: source/logger.cpp
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/logger.o source/logger.cpp

${OBJECTDIR}/source/main.o: source/main.cpp
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

${OBJECTDIR}/source/shader.o: source/shader.cpp
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/shader.o source/shader.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
