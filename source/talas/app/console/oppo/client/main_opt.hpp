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
///   Date: 8/16/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_OPPO_CLIENT_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_OPPO_CLIENT_MAIN_OPT_HPP

#include "talas/app/console/network/protocol/crlf/client/main.hpp"

#define TALAS_APP_CONSOLE_OPPO_PORT "23"

namespace talas {
namespace app {
namespace console {
namespace oppo {
namespace client {

///////////////////////////////////////////////////////////////////////
/// class main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = talas::app::console::network::protocol::crlf::client::main, 
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
    main_optt()
    : power_on_("POW ON"), power_off_("POW OFF"), power_("POW"), 
      request_(power_), 
      port_(TALAS_APP_CONSOLE_OPPO_PORT) {
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
    string_t power_on_, power_off_, power_, request_;
    virtual int before_write_request(writer_t& writer, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        request.assign("#");
        request.append(request_);
        request.append("\r\n");
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t port_;
    virtual string_t& port() const {
        return (string_t&)port_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace client
} /// namespace oppo
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// ndef TALAS_APP_CONSOLE_OPPO_CLIENT_MAIN_OPT_HPP
