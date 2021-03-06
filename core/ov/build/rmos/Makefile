
#   $Id: Makefile,v 1.8 2005-08-17 08:20:47 ansgar Exp $
#
#   Copyright (C) 1998
#   Lehrstuhl fuer Prozessleittechnik,
#   D-52056 Aachen, Germany.
#   All rights reserved.
#
#   Author: Dirk Meyer <dirk@plt.rwth-aachen.de>
#
#   This file is part of the ACPLT/OV Package 
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

#	History:
#	--------
#	18-Jun-1999 Dirk Meyer <dirk@plt.rwth-aachen.de>: File created.



#	Plattform
#	---------

SYSTEM = RMOS
SYSDIR = rmos

#	Filename conventions
#	--------------------

_OBJ = .obj
_LIB = .lib
_EXE = .exe
_DLL = .dll
_RES = .res

#	Platform-specific definitions
#	-----------------------------

ACPLTKS_PLATFORM_DEFINES	= -DFD_SETSIZE=128
OV_DEBUG					=
ifdef OV_DEBUG
OV_DODEBUG	=	-DOV_DEBUG
else
OV_DODEBUG	=
endif
OV_PLATFORM_DEFINES			= $(OV_DODEBUG)

#	Platform-specific C libraries
#	-----------------------------

C_OBJS = $(RMOS_LIBRARY_DIR)cstrtbfp.obj
C_LIBS = rmfsk2ib.lib m7apibl.lib rm3bcc.lib rmfcrifb.lib rmfhlib.lib

#	Compiler
#	--------

COMPILER		= BORLAND

MKLIBTAB		= mklibtab
CODEGEN			= ../nt/$(OV_CODEGEN_EXE)
FLEX			= flex
BISON			= bison
CPP 			= cpp

CC				= bcc32
CC_FLAGS		= -w -v -pc -wsig- -a8 -O2 -d
COMPILE_C		= $(CC) $(CC_FLAGS) $(DEFINES) $(INCLUDES) -c

LINK			= tlink32 -L$(RMOS_LIBRARY_DIR) -Tpe -ap -c
LD				= $(CC) $(CC_FLAGS) -tWDE

CXX				= bcc32 -P
CXX_FLAGS		= $(CC_FLAGS)
CXX_COMPILE		= $(CXX) $(CXX_FLAGS) $(DEFINES) $(INCLUDES) -c

CXX_LINK		= $(CXX) $(CXX_FLAGS)

AR	 			= tlib /P64

IMPLIB			= implib
IMPDEF			= impdef

RC 				= brc32 -i$(OV_INCLUDE_DIR)

#	Include generic part
#	--------------------

include ../generic.mk

#	C-Includes
#	----------

C_INCLUDES = -I$(RMOS_INCLUDE_DIR)

#	ONCRPC-Includes and defines
#	---------------------------

LIBRPC_DEFINES = \
	$(LIBRPC_PLATFORM_DEFINES) \
	-DRMOS32
LIBRPC_INCLUDES	= \
	-I$(ONCRPC_INCLUDE_DIR)

#	all defines and includes together
#	---------------------------------

DEFINES	 = $(LIBRPC_DEFINES) $(ACPLTKS_DEFINES) $(OV_DEFINES)
INCLUDES = $(C_INCLUDES) $(LIBRPC_INCLUDES) $(ACPLTKS_INCLUDES) $(OV_INCLUDES)

#	presupposed libraries
#	---------------------

LIBMPM_LIB			= $(LIBMPM_SOURCE_DIR)libmpm$(_LIB)

LIBRPC_LIB			= $(ONCRPC_BIN_DIR)oncrpc$(_LIB)

ACPLTKS_LIBS			= $(ACPLT_PLT_BUILD_DIR)libplt$(_LIB) $(LIBRPC_LIB)

#	Targets
#	-------

targets: $(OV_LIBOV_LIB) $(OV_DBUTIL_EXE) $(OV_LIBOVKS_LIB) $(OV_SERVER_EXE) $(KSHISTLIB_LIB)


example: $(EXAMPLE)
	@

all: targets

#   Implicit Rules
#   --------------

.c$(_OBJ):
	$(COMPILE_C) $< -o$@

.cpp$(_OBJ):
	$(CXX_COMPILE) -Jgx $< -o$@

.rc$(_RES):
	$(RC) -r -fo$@ $<

.lex.c:
	$(FLEX) -o$@ $<

.y.c:
	$(BISON) -t -d -o$@ $<

.ovm.c:
	$(CODEGEN) -I $(OV_MODEL_DIR) -f $(subst /,\\, $<) -l $(notdir $(basename $<))

.ovm.h:
	$(CODEGEN) -I $(OV_MODEL_DIR) -f $(subst /,\\, $<) -l $(notdir $(basename $<))

#   Dependencies
#   ------------

depend:
	@echo Unable to generate dependencies under Borland C++/RMOS

#	Table of statically linked ACPLT/OV libraries
#	---------------------------------------------

OV_LIBRARIES = $(EXAMPLE_LIB) $(KSHISTLIB_LIB)

$(OV_LIBTABLE_SRC) : $(OV_LIBRARIES)
	@echo Generating static library table file '$@'
	$(MKLIBTAB) $@ $(basename $(notdir $^))

#	Libraries
#	---------

#	ACPLT/OV library

$(OV_LIBOV_LIB) : $(OV_LIBOV_OBJ)
	@echo $(foreach object, $?, +-$(notdir $(object))) > respfile
	$(AR) $@ @respfile
	@del respfile


#	ACPLT/OV library for ACPLT/KS integration

$(OV_LIBOVKS_LIB) : $(KS_LIBOVKS_OBJ) $(OV_LIBOVKS_OBJ)
	@echo $(foreach object, $?, +-$(notdir $(object))) > respfile
	$(AR) $@ @respfile
	@del respfile

ov_ksserver$(_OBJ) : $(OV_SOURCE_LIBOVKS_DIR)ov_ksserver.c
	$(CXX_COMPILE) -Jgd $< -o$@

ov_ksclient$(_OBJ) : $(OV_SOURCE_LIBOVKS_DIR)ov_ksclient.c
	$(CXX_COMPILE) -Jgx $< -o$@

#	ACPLT/OV example library

$(EXAMPLE_LIB) : $(EXAMPLE_OBJ)
	@echo $(foreach object, $?, +-$(object)) > respfile
	$(AR) $@ @respfile
	@del respfile

#	ACPLT/OV example library

$(KSHISTLIB_LIB) : $(KSHISTLIB_OBJ)
	@echo $(foreach object, $?, +-$(object)) > respfile
	$(AR) $@ @respfile
	@del respfile

#	Executables
#	-----------

#	ACPLT/OV database utility

$(OV_DBUTIL_EXE) : $(OV_DBUTIL_OBJ) $(OV_LIBOV_LIB) $(LIBMPM_LIB)
	@echo $(C_OBJS) $(filter %$(_OBJ), $^), $@,, $(subst /,\, $(filter %$(_LIB), $^ )) $(C_LIBS) > respfile
	$(LINK) @respfile
	@del respfile

#	ACPLT/KS-Server for ACPLT/OV

$(OV_SERVER_EXE) : $(OV_SERVER_OBJ) $(OV_LIBTABLE_OBJ) $(OV_LIBRARIES) $(OV_LIBOVKS_LIB) $(ACPLTKS_LIBS) $(OV_LIBOV_LIB) $(LIBMPM_LIB)
	@echo $(C_OBJS) $(filter %$(_OBJ), $^), $@,, $(subst /,\, $(filter %$(_LIB), $^ )) $(C_LIBS) > respfile
	$(LINK) @respfile
	@del respfile 

#	Install
#	-------

install : all
	@echo Installing files to '$(ACPLT_BIN_DIR)'
	@-for %i in ( $(OV_LIBOV_LIB) $(OV_LIBOVKS_LIB) ) do copy %i $(subst /,\, $(ACPLT_BIN_DIR))
	@echo Done.
	@echo Installing files to c:\siemens\step7\s7proj\test_m7\hrs
	@copy ov_dbutil.exe c:\siemens\step7\s7proj\test_m7\hrs\p0000010\OVdbutil.exe
	@copy ov_server.exe c:\siemens\step7\s7proj\test_m7\hrs\p0000011\OVserver.exe
	@echo Done.

#	Clean up
#	--------

clean:
	@del *.c *.h *.bak *.map *$(_LIB) *$(_OBJ) *$(_EXE) respfile

#	Include dependencies
#	--------------------

include depend.rm

