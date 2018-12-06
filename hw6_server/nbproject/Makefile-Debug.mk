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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/cache.o \
	${OBJECTDIR}/evictor_fifo.o \
	${OBJECTDIR}/evictor_lru.o \
	${OBJECTDIR}/main_server.o \
	${OBJECTDIR}/server.o \
	${OBJECTDIR}/server_example.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread -lboost_system
CXXFLAGS=-pthread -lboost_system

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw6_server

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw6_server: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw6_server ${OBJECTFILES} ${LDLIBSOPTIONS} -l pistache

${OBJECTDIR}/cache.o: cache.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ipistache -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cache.o cache.cpp

${OBJECTDIR}/evictor_fifo.o: evictor_fifo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ipistache -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/evictor_fifo.o evictor_fifo.cpp

${OBJECTDIR}/evictor_lru.o: evictor_lru.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ipistache -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/evictor_lru.o evictor_lru.cpp

${OBJECTDIR}/main_server.o: main_server.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ipistache -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_server.o main_server.cpp

${OBJECTDIR}/server.o: server.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ipistache -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/server.o server.cpp

${OBJECTDIR}/server_example.o: server_example.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ipistache -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/server_example.o server_example.cpp

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
