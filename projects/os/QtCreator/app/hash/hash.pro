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
#   File: hash.pro
#
# Author: $author$
#   Date: 8/25/2025
#
# os specific QtCreator project .pro file for framework talas executable hash
########################################################################
# Depends: bn;mp;rostra;nadir;fila;crono;rete;stara
#
# Debug: talas/build/os/QtCreator/Debug/bin/hash
# Release: talas/build/os/QtCreator/Release/bin/hash
# Profile: talas/build/os/QtCreator/Profile/bin/hash
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/hash/hash.pri)

TARGET = $${hash_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${hash_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${hash_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${hash_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${hash_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${hash_HEADERS} \
$${hash_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${hash_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${hash_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${hash_LIBS} \
$${FRAMEWORKS} \

########################################################################
