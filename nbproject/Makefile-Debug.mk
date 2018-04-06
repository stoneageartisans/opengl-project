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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/Application.o \
	${OBJECTDIR}/source/Logger.o \
	${OBJECTDIR}/source/Shader.o \
	${OBJECTDIR}/source/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../libraries/glad-core-3.3/lib/mingw-64 -L../../../libraries/glfw-3.2.1.bin.WIN64/lib-mingw-w64 -lglad -lglfw3dll -lopengl32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk start-win32.exe

start-win32.exe: ${OBJECTFILES}
	${LINK.cc} -o start-win32 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/source/Application.o: source/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Application.o source/Application.cpp

${OBJECTDIR}/source/Logger.o: source/Logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Logger.o source/Logger.cpp

${OBJECTDIR}/source/Shader.o: source/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Shader.o source/Shader.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../libraries/glfw-3.2.1.bin.WIN64/include -I../../../libraries/glad-core-3.3/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} start-win32.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
