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
#   File: random.pro
#
# Author: $author$
#   Date: 8/25/2025
#
# os specific QtCreator project .pro file for framework talas executable random
########################################################################
# Depends: bn;mp;rostra;nadir;fila;crono;rete;stara
#
# Debug: talas/build/os/QtCreator/Debug/bin/random
# Release: talas/build/os/QtCreator/Release/bin/random
# Profile: talas/build/os/QtCreator/Profile/bin/random
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/random/random.pri)

TARGET = $${random_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${random_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${random_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${random_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${random_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${random_HEADERS} \
$${random_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${random_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${random_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${random_LIBS} \
$${FRAMEWORKS} \

########################################################################
