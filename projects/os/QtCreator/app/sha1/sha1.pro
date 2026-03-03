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
#   File: sha1.pro
#
# Author: $author$
#   Date: 8/25/2025
#
# os specific QtCreator project .pro file for framework talas executable sha1
########################################################################
# Depends: bn;mp;rostra;nadir;fila;crono;rete;stara
#
# Debug: talas/build/os/QtCreator/Debug/bin/sha1
# Release: talas/build/os/QtCreator/Release/bin/sha1
# Profile: talas/build/os/QtCreator/Profile/bin/sha1
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/sha1/sha1.pri)

TARGET = $${sha1_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${sha1_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${sha1_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${sha1_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${sha1_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${sha1_HEADERS} \
$${sha1_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${sha1_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${sha1_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${sha1_LIBS} \
$${FRAMEWORKS} \

########################################################################
