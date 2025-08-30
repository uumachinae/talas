///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 8/15/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_CLIENT_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_CLIENT_MAIN_OPT_HPP

#include "talas/app/console/network/client/main.hpp"

namespace talas {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace crlf {
namespace client {

///////////////////////////////////////////////////////////////////////
/// class main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = talas::app::console::network::client::main, 
 class TImplements = typename TExtends::Implements>

class EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef main_optt Derives;

    typedef typename Extends::char_t char_t;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::reader_t reader_t;
    typedef typename Extends::writer_t writer_t;
    typedef typename Extends::file_t file_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename Extends::in_reader_t in_reader_t;
    typedef typename Extends::out_writer_t out_writer_t;
    typedef typename Extends::err_writer_t err_writer_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int read_response(string_t& response, reader_t& reader, int argc, char_t** argv, char_t** env) {
        char_t* chars = 0; size_t size = 0;
        int err = 0;
        
        if ((chars = this->recved(size)) && (size)) {
            ssize_t amount = 0, count = 0;
            string_t response_line;

            TALAS_LOG_DEBUG("reader.read_crlf(chars, size = " << size << "))...");
            if (0 < (amount = reader.read_crlf(chars, size))) {
                TALAS_LOG_DEBUG("..." << amount << " = reader.read_crlf(chars, size = " << size << "))");
                response.assign(chars, amount);
            } else {
                TALAS_LOG_ERROR("...failed" << amount << " = reader.read_crlf(chars, size = " << size << "))...");
                err = 1;
            }
        } else {
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace client
} /// namespace crlf
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_CLIENT_MAIN_OPT_HPP
