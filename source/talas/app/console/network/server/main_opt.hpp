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
///   Date: 8/12/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPT_HPP

#include "talas/app/console/network/base/main.hpp"

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPT "accept-one"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTARG "[{ * | name | ddd.ddd.ddd.ddd }[:{ 0..2^16-1 }]]"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTUSE "Accept one"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTVAL_S "1::"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C '1'
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPT "accept"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTARG "[{ * | name | ddd.ddd.ddd.ddd }[:{ 0..2^16-1 }]]"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTUSE "Accept"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTVAL_S "a::"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTVAL_C 'a'
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPT "host"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTARG "[{ * | name | ddd.ddd.ddd.ddd }]"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTUSE "Host name or address"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_S "o::"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_C 'o'
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPT "port"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTARG "[{ 0..2^16-1 }]"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTUSE "Port number"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_S "p::"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_C 'p'
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPT "relay-host"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd }]"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTUSE "Relay host name or address"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTVAL_S "s::"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTVAL_C 's'
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPT "relay-port"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTARG "[{ 0..2^16-1 }]"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTUSE "Relay port number"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTVAL_S "t::"
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTVAL_C 't'
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTVAL_S \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTVAL_S \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_S \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_S \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTVAL_S \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTVAL_S \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTION \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTION \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTION \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTION \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTION \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_CHARS \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   TALAS_APP_CONSOLE_MAIN_OPTIONS_CHARS \

#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_OPTIONS \
   TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   TALAS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ARGS 0
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ARGV 0,

namespace talas {
namespace app {
namespace console {
namespace network {
namespace server {

///////////////////////////////////////////////////////////////////////
/// class main_optt
///////////////////////////////////////////////////////////////////////
template <class TExtends = network::base::maint<>, class TImplements = typename TExtends::Implements>
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
    main_optt(): plain_sockets_run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }

protected:
    typedef typename TExtends::socket_t socket_t;
    typedef typename TExtends::socket_reader_t socket_reader_t;
    typedef typename TExtends::socket_writer_t socket_writer_t;
    typedef typename TExtends::sized_reader_t sized_reader_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*plain_sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int plain_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->plain_sockets_run_)) {
            err = (this->*plain_sockets_run_)(argc, argv, env);
        } else {
            err = Extends::plain_sockets_run(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int plain_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& host = this->accept_host();
        const char_t *host_chars = 0; size_t length = 0;
        
        if ((host_chars = host.has_chars(length))) {
            const string_t& port = this->accept_port();
            const char *port_chars = 0;

            TALAS_LOG_DEBUG("...host = \"" << host << "\"");
            if ((port_chars = port.has_chars(length))) {
                size_t portno = 0;
                
                TALAS_LOG_DEBUG("...port = \"" << port << "\"");
                if ((0 < (portno = port.to_unsigned()))) {
                    const string_t& host_any = this->host_any();
                    signed unequal = 0;
                    bool ep_attached = false;
                    talas::network::ip::v4::endpoint ep;
                    
                    TALAS_LOG_DEBUG("...portno = " << portno << "");
                    if (!(unequal = host_any.compare(host))) {

                        TALAS_LOG_DEBUG("ep.attach(portno = " << portno << ")...");
                        if ((ep.attach(portno))) {
                            ep_attached = true;
                        } else {
                        }
                    } else {

                        TALAS_LOG_DEBUG("ep.attach(host = \"" << host << "\", portno = " << portno << ")...");
                        if ((ep.attach(host, portno))) {
                            ep_attached = true;
                        } else {
                        }
                    }
                    if ((ep_attached)) {
                        talas::network::ip::v4::tcp::transport tp;
                        socket_t s(*this);
                        
                        TALAS_LOG_DEBUG("s.open(tp)...");
                        if ((s.open(tp))) {
                            
                            TALAS_LOG_DEBUG("s.listen(ep)...");
                            if ((s.listen(ep))) {
                                socket_t sk(*this);

                                for (bool done = false; !done; ) {
                                    
                                    TALAS_LOG_DEBUG("sk.closed()...");
                                    if (!(done = !(sk.closed()))) {
                                        
                                        TALAS_LOG_DEBUG("s.accept(sk, ep)...");
                                        if (!(done = !(s.accept(sk, ep)))) {
                                            if (!(err = all_server_sockets_run(sk, argc, argv, env))) {
                                                done = (this->accept_one()) || (this->restart()) || (this->stop());
                                            } else {
                                                done = true;
                                            }
                                        } else {
                                        }
                                    } else {
                                    }
                                }
                            } else {
                            }
                            TALAS_LOG_DEBUG("s.close()...");
                            if ((s.close())) {
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_plain_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_plain_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_plain_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_plain_server_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = plain_server_sockets_run(argc, argv, env);
            if ((err2 = after_plain_server_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        plain_sockets_run_ = &Derives::all_plain_server_sockets_run;
        return err;
    }
    virtual int before_set_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_server_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_server_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = set_server_sockets_run(argc, argv, env);
            if ((err2 = after_set_server_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int server_sockets_run(socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_server_sockets_run(socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_server_sockets_run(socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_server_sockets_run(socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_server_sockets_run(socket, argc, argv, env))) {
            int err2 = 0;
            err = server_sockets_run(socket, argc, argv, env);
            if ((err2 = after_server_sockets_run(socket, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_set_sockets_run(argc, argv, env))) {
            if (!(err = this->all_set_server_sockets_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int before_set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_server_run(argc, argv, env))) {
            int err2 = 0;
            err = set_server_run(argc, argv, env);
            if ((err2 = after_set_server_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_accept_one_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_accept_one();
        err = this->on_accept_option(optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual const char_t* accept_one_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTARG;
        return chars;
    }
    virtual int on_accept_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_server_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* accept_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTARG;
        return chars;
    }
    virtual int on_accept_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = Extends::on_accept_host_option(optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual const char_t* accept_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTARG;
        return chars;
    }
    virtual int on_accept_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = Extends::on_accept_port_option(optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual const char_t* accept_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTARG;
        return chars;
    }
    virtual int on_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = Extends::on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual const char_t* relay_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTARG;
        return chars;
    }
    virtual int on_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = Extends::on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
        return err;
    }
    virtual const char_t* relay_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTARG;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C:
            err = this->on_accept_one_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTVAL_C:
            err = this->on_accept_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_C:
            err = this->on_accept_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_C:
            err = this->on_accept_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTVAL_C:
            err = this->on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTVAL_C:
            err = this->on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_ONE_OPTVAL_C:
            chars = accept_one_option_usage(optarg, longopt);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_OPTVAL_C:
            chars = accept_option_usage(optarg, longopt);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_HOST_OPTVAL_C:
            chars = accept_host_option_usage(optarg, longopt);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ACCEPT_PORT_OPTVAL_C:
            chars = accept_port_option_usage(optarg, longopt);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_HOST_OPTVAL_C:
            chars = relay_host_option_usage(optarg, longopt);
            break;
        case TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_RELAY_PORT_OPTVAL_C:
            chars = relay_port_option_usage(optarg, longopt);
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace talas 

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_OPT_HPP 