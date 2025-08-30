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
///   Date: 8/14/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CR_SERVER_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CR_SERVER_MAIN_OPT_HPP

#include "talas/app/console/network/server/main.hpp"

namespace talas {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace cr {
namespace server {

///////////////////////////////////////////////////////////////////////
/// class main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = talas::app::console::network::server::main, 
 class TImplements = typename TExtends::Implements>

class EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef main_optt Derives;

    typedef typename TExtends::writer_t writer_t;
    typedef typename TExtends::reader_t reader_t;
    typedef typename TExtends::string_t string_t;
    typedef typename TExtends::char_t char_t;
    
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
    typedef typename TExtends::socket_t socket_t;
    typedef typename TExtends::socket_reader_t socket_reader_t;
    typedef typename TExtends::socket_writer_t socket_writer_t;
    typedef typename TExtends::sized_reader_t sized_reader_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int read_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        char_t* chars = 0; size_t size = 0;
        int err = 0;
        
        if ((chars = this->recved(size)) && (size)) {
            ssize_t amount = 0, count = 0;
            string_t request_line;

            TALAS_LOG_DEBUG("reader.read_cr(chars, size = " << size << "))...");
            if (0 < (amount = reader.read_cr(chars, size))) {
                TALAS_LOG_DEBUG("..." << amount << " = reader.read_cr(chars, size = " << size << "))");
                request.assign(chars, amount);
            } else {
                TALAS_LOG_ERROR("...failed" << amount << " = reader.read_cr(chars, size = " << size << "))...");
                err = 1;
            }
        } else {
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_process_request(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        
        if ((chars = request.has_chars(length))) {
            string_t& response = this->response();
            
            this->outln(chars, length);
            response.assign(chars, length);
        }
        return err;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server
} /// namespace cr
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CR_SERVER_MAIN_OPT_HPP
