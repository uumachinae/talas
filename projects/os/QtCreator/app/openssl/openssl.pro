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
#   File: openssl.pro
#
# Author: $author$
#   Date: 8/30/2025
#
# os specific QtCreator project .pro file for framework talas executable openssl
########################################################################
# Depends: libressl;openssl;bn;mp;rostra;nadir;fila;crono;rete;stara
#
# Debug: talas/build/os/QtCreator/Debug/bin/openssl
# Release: talas/build/os/QtCreator/Release/bin/openssl
# Profile: talas/build/os/QtCreator/Profile/bin/openssl
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/openssl/openssl.pri)

TARGET = $${openssl_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${openssl_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${openssl_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${openssl_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${openssl_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${openssl_HEADERS} \
$${openssl_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${openssl_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${openssl_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${openssl_LIBS} \
$${FRAMEWORKS} \

########################################################################
