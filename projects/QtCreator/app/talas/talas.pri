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
#   File: talas.pri
#
# Author: $author$
#   Date: 8/23/2025
#
# generic QtCreator project .pri file for framework talas executable talas
########################################################################

########################################################################
# talas

# talas_exe TARGET
#
talas_exe_TARGET = talas

# talas_exe INCLUDEPATH
#
talas_exe_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# talas_exe DEFINES
#
talas_exe_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# talas_exe OBJECTIVE_HEADERS
#
#talas_exe_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/talas/main.hh \

# talas_exe OBJECTIVE_SOURCES
#
#talas_exe_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/talas/main.mm \

########################################################################
# talas_exe HEADERS
#
talas_exe_HEADERS += \
$${TALAS_SRC}/xos/io/protocol/crypto/output.hpp \
$${TALAS_SRC}/xos/lib/bn/version.hpp \
$${TALAS_SRC}/xos/lib/mp/version.hpp \
$${TALAS_SRC}/xos/lib/mpn/version.hpp \
$${TALAS_SRC}/xos/lib/mpz/version.hpp \
$${TALAS_SRC}/xos/lib/talas/version.hpp \
\
$${TALAS_SRC}/xos/crypto/array.hpp \
$${TALAS_SRC}/xos/crypto/output.hpp \
$${TALAS_SRC}/xos/crypto/base/error.hpp \
$${TALAS_SRC}/xos/crypto/base/exception.hpp \
$${TALAS_SRC}/xos/crypto/base/extend.hpp \
$${TALAS_SRC}/xos/crypto/base/implement.hpp \
$${TALAS_SRC}/xos/crypto/base.hpp \
\
$${TALAS_SRC}/xos/crypto/cipher/aes/devine/constants.hpp \
$${TALAS_SRC}/xos/crypto/cipher/aes/devine/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/aes/devine/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/aes/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/aes/implement.hpp \
$${TALAS_SRC}/xos/crypto/cipher/base.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des/implement.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des/openssl/constants.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des/openssl/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des3/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des3/implement.hpp \
$${TALAS_SRC}/xos/crypto/cipher/des3/openssl/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/identity/cifra/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/identity/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/identity/implement.hpp \
$${TALAS_SRC}/xos/crypto/cipher/identity/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/implement.hpp \
$${TALAS_SRC}/xos/crypto/cipher/implemented/aes.hpp \
$${TALAS_SRC}/xos/crypto/cipher/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/rc4/etiris/implemented.hpp \
$${TALAS_SRC}/xos/crypto/cipher/rc4/extend.hpp \
$${TALAS_SRC}/xos/crypto/cipher/rc4/implement.hpp \
$${TALAS_SRC}/xos/crypto/cipher.hpp \
\
$${TALAS_SRC}/xos/crypto/hash/algorithm.hpp \
$${TALAS_SRC}/xos/crypto/hash/extend.hpp \
$${TALAS_SRC}/xos/crypto/hash/implement.hpp \
$${TALAS_SRC}/xos/crypto/hash/implemented/sha256.hpp \
$${TALAS_SRC}/xos/crypto/hash/implemented.hpp \
$${TALAS_SRC}/xos/crypto/hash/md5.hpp \
$${TALAS_SRC}/xos/crypto/hash/openssl/md5.hpp \
$${TALAS_SRC}/xos/crypto/hash/openssl/sha1.hpp \
$${TALAS_SRC}/xos/crypto/hash/openssl/sha256.hpp \
$${TALAS_SRC}/xos/crypto/hash/openssl/sha512.hpp \
$${TALAS_SRC}/xos/crypto/hash/sha1.hpp \
$${TALAS_SRC}/xos/crypto/hash/sha256.hpp \
$${TALAS_SRC}/xos/crypto/hash/sha512.hpp \
$${TALAS_SRC}/xos/crypto/hash.hpp \
\
$${TALAS_SRC}/xos/crypto/pseudo/random/number/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/implemented.hpp \
$${TALAS_SRC}/xos/crypto/random/number/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/number/reader.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/bn/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/bn/license.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/bn/miller_rabin.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/bn/number.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/bn/reader.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/miller_rabin.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/mp/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/mp/license.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/mp/miller_rabin.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/mp/number.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/mp/reader.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/reader.hpp \
$${TALAS_SRC}/xos/crypto/random/prime/small_primes.hpp \
$${TALAS_SRC}/xos/crypto/random/pseudo/generator.hpp \
$${TALAS_SRC}/xos/crypto/random/reader.hpp \
$${TALAS_SRC}/xos/crypto/random.hpp \
\
$${TALAS_SRC}/xos/crypto/ecc/curve25519/array.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/base_point.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/google/donna/public_key.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/key.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/msotoodeh/public_key.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/private_key.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/public_key.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/public_keys.hpp \
$${TALAS_SRC}/xos/crypto/ecc/curve25519/shared_secret.hpp \
\
$${TALAS_SRC}/xos/crypto/rsa/bn/key.hpp \
$${TALAS_SRC}/xos/crypto/rsa/bn/key_generator.hpp \
$${TALAS_SRC}/xos/crypto/rsa/bn/license.hpp \
$${TALAS_SRC}/xos/crypto/rsa/bn/private_key.hpp \
$${TALAS_SRC}/xos/crypto/rsa/bn/public_key.hpp \
$${TALAS_SRC}/xos/crypto/rsa/key/extend.hpp \
$${TALAS_SRC}/xos/crypto/rsa/key/implement.hpp \
$${TALAS_SRC}/xos/crypto/rsa/keys.hpp \
$${TALAS_SRC}/xos/crypto/rsa/mp/key.hpp \
$${TALAS_SRC}/xos/crypto/rsa/mp/key_generator.hpp \
$${TALAS_SRC}/xos/crypto/rsa/mp/license.hpp \
$${TALAS_SRC}/xos/crypto/rsa/mp/private_key.hpp \
$${TALAS_SRC}/xos/crypto/rsa/mp/public_key.hpp \
$${TALAS_SRC}/xos/crypto/rsa/private_key/extend.hpp \
$${TALAS_SRC}/xos/crypto/rsa/private_key/implement.hpp \
$${TALAS_SRC}/xos/crypto/rsa/public_key/extend.hpp \
$${TALAS_SRC}/xos/crypto/rsa/public_key/implement.hpp \
\
$${TALAS_SRC}/xos/protocol/crypto/pseudo/random/generator.hpp \
$${TALAS_SRC}/xos/protocol/crypto/pseudo/random/reader.hpp \
$${TALAS_SRC}/xos/protocol/crypto/random/generator.hpp \
$${TALAS_SRC}/xos/protocol/crypto/random/reader.hpp \
\
$${TALAS_SRC}/xos/protocol/sttp/base/output.hpp \
$${TALAS_SRC}/xos/protocol/sttp/client/message/default_plain_text.hpp \
$${TALAS_SRC}/xos/protocol/sttp/client/output.hpp \
$${TALAS_SRC}/xos/protocol/sttp/plaintext/messages.hpp \
$${TALAS_SRC}/xos/protocol/sttp/server/message/default_plain_text.hpp \
$${TALAS_SRC}/xos/protocol/sttp/server/output.hpp \
\
$${TALAS_SRC}/xos/protocol/tls/array.hpp \
$${TALAS_SRC}/xos/protocol/tls/bulk/cipher/algorithm.hpp \
$${TALAS_SRC}/xos/protocol/tls/cipher/suite.hpp \
$${TALAS_SRC}/xos/protocol/tls/cipher/suites.hpp \
$${TALAS_SRC}/xos/protocol/tls/cipher/type.hpp \
$${TALAS_SRC}/xos/protocol/tls/ciphertext.hpp \
$${TALAS_SRC}/xos/protocol/tls/client/hello.hpp \
$${TALAS_SRC}/xos/protocol/tls/client/key/exchange/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/compression/method.hpp \
$${TALAS_SRC}/xos/protocol/tls/compression/methods.hpp \
$${TALAS_SRC}/xos/protocol/tls/connection/end.hpp \
$${TALAS_SRC}/xos/protocol/tls/content/type.hpp \
$${TALAS_SRC}/xos/protocol/tls/crypto/output.hpp \
$${TALAS_SRC}/xos/protocol/tls/decrypted/premaster/secret.hpp \
$${TALAS_SRC}/xos/protocol/tls/encrypted/premaster/secret.hpp \
$${TALAS_SRC}/xos/protocol/tls/generic/block/cipher.hpp \
$${TALAS_SRC}/xos/protocol/tls/gmt/unix/time.hpp \
$${TALAS_SRC}/xos/protocol/tls/handshake/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/handshake/type/which.hpp \
$${TALAS_SRC}/xos/protocol/tls/hash/algorithm/code.hpp \
$${TALAS_SRC}/xos/protocol/tls/hello/random.hpp \
$${TALAS_SRC}/xos/protocol/tls/key/exchange/algorithm.hpp \
$${TALAS_SRC}/xos/protocol/tls/mac/algorithm.hpp \
$${TALAS_SRC}/xos/protocol/tls/master/secret.hpp \
$${TALAS_SRC}/xos/protocol/tls/message/part.hpp \
$${TALAS_SRC}/xos/protocol/tls/pkcs1/decoded/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/pkcs1/decoded/premaster/secret.hpp \
$${TALAS_SRC}/xos/protocol/tls/pkcs1/encoded/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/pkcs1/encoded/premaster/secret.hpp \
$${TALAS_SRC}/xos/protocol/tls/plaintext.hpp \
$${TALAS_SRC}/xos/protocol/tls/premaster/secret/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/premaster/secret/random.hpp \
$${TALAS_SRC}/xos/protocol/tls/prf/algorithm.hpp \
$${TALAS_SRC}/xos/protocol/tls/protocol/version/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/protocol/version/part.hpp \
$${TALAS_SRC}/xos/protocol/tls/protocol/version/which.hpp \
$${TALAS_SRC}/xos/protocol/tls/protocol/version.hpp \
$${TALAS_SRC}/xos/protocol/tls/pseudo/random/function.hpp \
$${TALAS_SRC}/xos/protocol/tls/pseudo/random/reader.hpp \
$${TALAS_SRC}/xos/protocol/tls/random/bytes.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/bn/private_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/bn/public_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/gmp/private_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/gmp/public_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/implemented/private_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/implemented/public_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/private_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/rsa/public_key.hpp \
$${TALAS_SRC}/xos/protocol/tls/security/parameters.hpp \
$${TALAS_SRC}/xos/protocol/tls/server/key/exchange/message.hpp \
$${TALAS_SRC}/xos/protocol/tls/session/identifier.hpp \
$${TALAS_SRC}/xos/protocol/tls/signature/algorithm/code.hpp \
$${TALAS_SRC}/xos/protocol/tls/signature/hash/algorithm/code.hpp \
$${TALAS_SRC}/xos/protocol/tls/uinteger.hpp \
$${TALAS_SRC}/xos/protocol/tls/vector.hpp \
\
$${TALAS_SRC}/thirdparty/gnu/mp/acconfig.h \
$${TALAS_SRC}/thirdparty/gnu/mp/gmp-impl.h \
$${TALAS_SRC}/thirdparty/gnu/mp/gmp-mparam.h \
$${TALAS_SRC}/thirdparty/gnu/mp/gmp.h \
$${TALAS_SRC}/thirdparty/gnu/mp/longlong.h \
$${TALAS_SRC}/thirdparty/gnu/mp/mp.h \
$${TALAS_SRC}/thirdparty/gnu/mp/mpn/generic/gmp-mparam.h \
$${TALAS_SRC}/thirdparty/gnu/mp/mpn/sysdep.h \
$${TALAS_SRC}/thirdparty/gnu/mp/mpz_lsb.h \
$${TALAS_SRC}/thirdparty/gnu/mp/mpz_msb.h \
$${TALAS_SRC}/thirdparty/gnu/mp/stack-alloc.h \
$${TALAS_SRC}/thirdparty/gnu/mp/urandom.h \
\
$${TALAS_SRC}/thirdparty/openssl/bn/bn.h \
$${TALAS_SRC}/thirdparty/openssl/bn/bn_lcl.h \
$${TALAS_SRC}/thirdparty/openssl/bn/bn_lsb.h \
$${TALAS_SRC}/thirdparty/openssl/bn/bn_msb.h \
$${TALAS_SRC}/thirdparty/openssl/bn/bn_prime.h \
$${TALAS_SRC}/thirdparty/openssl/bn/cryptlib.h \
$${TALAS_SRC}/thirdparty/openssl/bn/dbdump.h \
$${TALAS_SRC}/thirdparty/openssl/bn/dbprintf.h \
$${TALAS_SRC}/thirdparty/openssl/bn/rand.h \
\
$${TALAS_SRC}/thirdparty/google/curve25519/curve25519-donna.h \
$${TALAS_SRC}/thirdparty/msotoodeh/curve25519/BaseTypes.h \
$${TALAS_SRC}/thirdparty/msotoodeh/curve25519/curve25519_mehdi.h \
$${TALAS_SRC}/thirdparty/msotoodeh/curve25519/curve25519_mehdi.hxx \
\
$${TALAS_SRC}/xos/app/console/crypto/base/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/aes/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/aes/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/base/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/des/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/des/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/des3/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/des3/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/rc4/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/cipher/rc4/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/code/base/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/code/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/code/base/to_main_output.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/base/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/md5/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/md5/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/sha1/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/sha1/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/sha256/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/sha256/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/sha512/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/hash/sha512/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/input/base/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/input/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/output/base/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/output/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/random/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/random/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/crypto/rsa/main.hpp \
$${TALAS_SRC}/xos/app/console/crypto/rsa/main_opt.hpp \
\
$${TALAS_SRC}/xos/app/console/network/sockets/protocol/sttp/base/main.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/protocol/sttp/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/protocol/sttp/client/main.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/protocol/sttp/client/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/protocol/sttp/server/main.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/protocol/sttp/server/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/protocol/sttp/base/main.hpp \
$${TALAS_SRC}/xos/app/console/protocol/sttp/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/protocol/sttp/client/main.hpp \
$${TALAS_SRC}/xos/app/console/protocol/sttp/client/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/protocol/sttp/server/main.hpp \
$${TALAS_SRC}/xos/app/console/protocol/sttp/server/main_opt.hpp \
\
$${TALAS_SRC}/xos/app/console/talas/version/main.hpp \
$${TALAS_SRC}/xos/app/console/talas/version/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/framework/version/main.hpp \
$${TALAS_SRC}/xos/app/console/framework/version/main_opt.hpp \

# talas_exe SOURCES
#
talas_exe_SOURCES += \
$${TALAS_SRC}/xos/app/console/talas/version/main.cpp \
$${TALAS_SRC}/xos/app/console/talas/version/main_opt.cpp \

########################################################################
# talas_exe FRAMEWORKS
#
talas_exe_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# talas_exe LIBS
#
talas_exe_LIBS += \
$${talas_LIBS} \

########################################################################
# NO Qt
QT -= gui core
