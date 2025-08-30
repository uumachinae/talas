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
#ifndef TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPT_HPP

#include "talas/app/console/network/protocol/crlf/client/main.hpp"
#include "talas/app/console/network/protocol/crlf/server/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_CHARS_EXTEND \

#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_OPTIONS_EXTEND \

#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_CHARS \
   TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_CHARS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   TALAS_APP_CONSOLE_MAIN_OPTIONS_CHARS \

#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_OPTIONS \
   TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_OPTIONS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   TALAS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_ARGS 0
#define TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_ARGV 0,

namespace talas {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace crlf {

///////////////////////////////////////////////////////////////////////
/// class main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = talas::app::console::network::protocol::crlf::client::maint
 <talas::app::console::network::protocol::crlf::client::main_optt
 <talas::app::console::network::protocol::crlf::server::maint
 <talas::app::console::network::protocol::crlf::server::main_optt
 <talas::app::console::network::client::maint
 <talas::app::console::network::client::main_optt
 <talas::app::console::network::server::maint
 <talas::app::console::network::server::main_optt<> > > > > > > >, 
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
    virtual const string_t set_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        string_t& host = this->host();
        if ((to) && (to[0])) {
            accept_host.assign(to);
            host.assign(to);
        }
        return accept_host;
    }
    virtual const string_t set_port(const char_t* to) {
        string_t& accept_port = this->accept_port();
        string_t& port = this->port();
        if ((to) && (to[0])) {
            accept_port.assign(to);
            port.assign(to);
        }
        return accept_port;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            chars = Extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_ARGS;
        static const char_t* _argv[] = {
            TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace crlf
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_PROTOCOL_CRLF_MAIN_OPT_HPP
