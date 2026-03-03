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
#   File: oppod.pri
#
# Author: $author$
#   Date: 8/31/2025
#
# generic QtCreator project .pri file for framework talas executable oppod
########################################################################

########################################################################
# oppod

# oppod TARGET
#
oppod_TARGET = oppod

# oppod INCLUDEPATH
#
oppod_INCLUDEPATH += \
$${talas_talas_INCLUDEPATH} \

# oppod DEFINES
#
oppod_DEFINES += \
$${talas_talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# oppod OBJECTIVE_HEADERS
#
#oppod_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/oppod/main.hh \

# oppod OBJECTIVE_SOURCES
#
#oppod_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/oppod/main.mm \

########################################################################
# oppod HEADERS
#
oppod_HEADERS += \
$${TALAS_SRC}/nadir/xos/io/main/logger.hpp \
\
$${TALAS_SRC}/talas/app/console/network/base/main_opt.hpp \
$${TALAS_SRC}/talas/app/console/network/base/main.hpp \
\
$${TALAS_SRC}/talas/app/console/network/client/main_opt.hpp \
$${TALAS_SRC}/talas/app/console/network/client/main.hpp \
\
$${TALAS_SRC}/talas/app/console/network/server/main_opt.hpp \
$${TALAS_SRC}/talas/app/console/network/server/main.hpp \
\
$${TALAS_SRC}/talas/app/console/network/protocol/crlf/client/main_opt.hpp \
$${TALAS_SRC}/talas/app/console/network/protocol/crlf/client/main.hpp \
\
$${TALAS_SRC}/talas/app/console/network/protocol/crlf/server/main_opt.hpp \
$${TALAS_SRC}/talas/app/console/network/protocol/crlf/server/main.hpp \
\
$${TALAS_SRC}/talas/app/console/oppo/client/main_opt.hpp \
$${TALAS_SRC}/talas/app/console/oppo/client/main.hpp \

# oppod SOURCES
#
oppod_SOURCES += \
$${TALAS_SRC}/nadir/xos/io/main/logger.cpp \
\
$${TALAS_SRC}/talas/app/console/network/protocol/crlf/server/main_opt.cpp \
$${TALAS_SRC}/talas/app/console/network/protocol/crlf/server/main.cpp \
$${TALAS_SRC}/talas/console/main_main.cpp \

########################################################################
# oppod FRAMEWORKS
#
oppod_FRAMEWORKS += \
$${talas_talas_FRAMEWORKS} \

# oppod LIBS
#
oppod_LIBS += \
$${talas_talas_LIBS} \

########################################################################
# NO Qt
QT -= gui core

