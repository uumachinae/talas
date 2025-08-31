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
///   Date: 2/14/2021, 8/12/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPT_HPP
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPT_HPP

#include "talas/app/console/main.hpp"
#include "talas/network/os/sockets.hpp"

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_ANY)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_ANY "*"
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_ANY)

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST "localhost"
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST)

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT "80"
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_HOST)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_HOST \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_ANY
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_HOST)

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_PORT)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_PORT \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_PORT)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_HOST)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_HOST \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_HOST)

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_PORT)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_PORT \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT 
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_PORT)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPT "host"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd }]"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTUSE "Host name or address"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTVAL_S "o::"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTVAL_C 'o'
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPT, \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTVAL_C}, \

#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPT "port"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTARG_RESULT 0
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTUSE "Port number"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTVAL_S "p::"
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTVAL_C 'p'
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTION \
   {TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPT, \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTARG_RESULT, \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTVAL_S \
   TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTVAL_S \

#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTION \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    TALAS_APP_CONSOLE_MAIN_OPTIONS_CHARS \

#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS \
    TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    TALAS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace talas {
namespace app {
namespace console {
namespace network {
namespace base {

///////////////////////////////////////////////////////////////////////
/// class main_optt
///////////////////////////////////////////////////////////////////////
template <class TExtends = talas::app::console::main, class TImplements = typename TExtends::Implements>
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
    main_optt(): run_(0), 
        host_any_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_ANY), 
        host_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST), 
        port_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT),
        accept_host_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_HOST), 
        accept_port_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_ACCEPT_PORT),
        relay_host_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_HOST), 
        relay_port_(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RELAY_PORT),
        accept_one_(false), keep_accept_(false), 
        restart_(false), stop_(false) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy): Extends(copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    /// class socket
    ///////////////////////////////////////////////////////////////////////
    typedef class EXPORT_CLASS socket: public talas::network::os::socket {
    public:
        socket(Derives& _main): main_(_main) {}
        Derives& main_;
    } socket_t; /// typedef class socket

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = this->usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = this->sockets_run(argc, argv, env);
            if ((err2 = this->after_sockets_run(argc, argv, env))) {
                if (!(err)) {
                    err = err2;
                }
            }
        }
        return err;
    }
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::all_sockets_run;
        return err;
    }
    virtual int before_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_run(argc, argv, env);
            if ((err2 = after_set_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_host_run(int argc, char_t** argv, char_t** env) {
        const string_t& host = this->host();
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int set_get_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_host_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_port_run(int argc, char_t** argv, char_t** env) {
        const string_t& port = this->port();
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = port.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int set_get_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_port_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_accept_host_run(int argc, char_t** argv, char_t** env) {
        const string_t& accept_host = this->accept_host();
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = accept_host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int set_get_accept_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_accept_host_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_accept_port_run(int argc, char_t** argv, char_t** env) {
        const string_t& accept_port = this->accept_port();
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = accept_port.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int set_get_accept_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_accept_port_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_relay_host_run(int argc, char_t** argv, char_t** env) {
        const string_t& relay_host = this->relay_host();
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = relay_host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int set_get_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_relay_host_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_relay_port_run(int argc, char_t** argv, char_t** env) {
        const string_t& relay_port = this->relay_port();
        const char_t* chars = 0;
        size_t length = 0;
        int err = 0;
        if ((chars = relay_port.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int set_get_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_relay_port_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_set_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_host(optarg);
            err = this->on_set_host(argc, argv, env);
        }
        return err;
    }
    virtual int on_get_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->on_get_host(argc, argv, env);
        return err;
    }
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_host_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = on_get_host_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTARG;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_set_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_port(optarg);
            err = this->on_set_port(argc, argv, env);
        }
        return err;
    }
    virtual int on_get_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->on_get_port(argc, argv, env);
        return err;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_port_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = on_get_port_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTUSE;
        optarg = TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTARG;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_set_accept_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_accept_host(optarg);
            err = this->on_set_accept_host(argc, argv, env);
        }
        return err;
    }
    virtual int on_get_accept_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->on_get_accept_host(argc, argv, env);
        return err;
    }
    virtual int on_accept_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_accept_host_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = on_get_accept_host_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_set_accept_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_accept_port(optarg);
            err = this->on_set_accept_port(argc, argv, env);
        }
        return err;
    }
    virtual int on_get_accept_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->on_get_accept_port(argc, argv, env);
        return err;
    }
    virtual int on_accept_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_accept_port_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = on_get_accept_port_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_set_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_relay_host(optarg);
            err = this->on_set_relay_host(argc, argv, env);
        }
        return err;
    }
    virtual int on_get_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->on_get_relay_host(argc, argv, env);
        return err;
    }
    virtual int on_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = on_get_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_set_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_relay_port(optarg);
            err = this->on_set_relay_port(argc, argv, env);
        }
        return err;
    }
    virtual int on_get_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->on_get_relay_port(argc, argv, env);
        return err;
    }
    virtual int on_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = on_get_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        switch(optval) {
        case TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTVAL_C:
            err = on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTVAL_C:
            err = on_port_option(optval, optarg, optname, optind, argc, argv, env);
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
        case TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HOST_OPTVAL_C:
            chars = host_option_usage(optarg, longopt);
            break;
        case TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_PORT_OPTVAL_C:
            chars = port_option_usage(optarg, longopt);
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t host_any_;
    virtual const string_t set_host_any(const char_t* to) {
        string_t& host_any = this->host_any();
        if ((to) && (to[0])) {
            host_any.assign(to);
        }
        return host_any;
    }
    virtual string_t& host_any() const {
        return (string_t&)host_any_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t host_;
    virtual int on_set_host(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_get_host(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_host_run;
        return err;
    }
    virtual const string_t set_host(const char_t* to) {
        string_t& host = this->host();
        if ((to) && (to[0])) {
            host.assign(to);
        }
        return host;
    }
    virtual string_t& host() const {
        return (string_t&)host_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t port_;
    virtual int on_set_port(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_get_port(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_port_run;
        return err;
    }
    virtual const string_t set_port(const char_t* to) {
        string_t& port = this->port();
        if ((to) && (to[0])) {
            port.assign(to);
        }
        return port;
    }
    virtual string_t& port() const {
        return (string_t&)port_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t accept_host_;
    virtual int on_set_accept_host(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_get_accept_host(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_accept_host_run;
        return err;
    }
    virtual const string_t set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to) && (to[0])) {
            accept_host.assign(to);
        }
        return accept_host;
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t accept_port_;
    virtual int on_set_accept_port(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_get_accept_port(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_accept_port_run;
        return err;
    }
    virtual const string_t set_accept_port(const char_t* to) {
        string_t& accept_port = this->accept_port();
        if ((to) && (to[0])) {
            accept_port.assign(to);
        }
        return accept_port;
    }
    virtual string_t& accept_port() const {
        return (string_t&)accept_port_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t relay_host_;
    virtual int on_set_relay_host(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_get_relay_host(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_relay_host_run;
        return err;
    }
    virtual const string_t set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to) && (to[0])) {
            relay_host.assign(to);
        }
        return relay_host;
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t relay_port_;
    virtual int on_set_relay_port(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_get_relay_port(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &Derives::get_relay_port_run;
        return err;
    }
    virtual const string_t set_relay_port(const char_t* to) {
        string_t& relay_port = this->relay_port();
        if ((to) && (to[0])) {
            relay_port.assign(to);
        }
        return relay_port;
    }
    virtual string_t& relay_port() const {
        return (string_t&)relay_port_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool accept_one_;
    virtual bool& set_accept_one(bool to = true) {
        bool& accept_one = this->accept_one();
        accept_one = to;
        return accept_one;
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool keep_accept_;
    virtual bool& set_keep_accept(bool to = true) {
        bool& keep_accept = this->keep_accept();
        keep_accept = to;
        return keep_accept;
    }
    virtual bool& keep_accept() const {
        return (bool&)keep_accept_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool restart_;
    virtual bool& set_restart(bool to = true) {
        bool& restart = this->restart();
        restart = to;
        return restart;
    }
    virtual bool& restart() const {
        return (bool&)restart_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool stop_;
    virtual bool& set_stop(bool to = true) {
        bool& stop = this->stop();
        stop = to;
        return stop;
    }
    virtual bool& stop() const {
        return (bool&)stop_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace talas 

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_OPT_HPP 