########################################################################
# Copyright (c) 1988-2025 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: des3.pro
#
# Author: $author$
#   Date: 8/24/2025
#
# os specific QtCreator project .pro file for framework talas executable des3
########################################################################
# Depends: bn;mp;rostra;nadir;fila;crono;rete;stara
#
# Debug: talas/build/os/QtCreator/Debug/bin/des3
# Release: talas/build/os/QtCreator/Release/bin/des3
# Profile: talas/build/os/QtCreator/Profile/bin/des3
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/des3/des3.pri)

TARGET = $${des3_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${des3_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${des3_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${des3_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${des3_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${des3_HEADERS} \
$${des3_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${des3_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${des3_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${des3_LIBS} \
$${FRAMEWORKS} \

########################################################################
