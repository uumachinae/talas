//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/22/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_STTP_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_STTP_SERVER_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/sttp/server/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace sttp {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::sttp::server::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    typedef typename extends::sequence_char_t sequence_char_t;
    typedef typename extends::char_sequence_t char_sequence_t;
    typedef typename extends::char_seeker_t char_seeker_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_writer_t char_writer_t;
    typedef typename extends::reader_string_t reader_string_t;
    typedef typename extends::string_reader_t string_reader_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef typename extends::string_output_t string_output_t;
    typedef typename extends::output_t output_t;
    typedef typename output_t::output_to_t output_to_t;
    typedef typename output_t::output_to_t::string_t output_to_string_t;

    //////////////////////////////////////////////////////////////////////////
    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*run_)(argc, argv, env)))...");
            if (!(err = (this->*run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
            if (!(err = extends::run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(err" << err << " = extends::run(argc, argv, env)))");
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...sockets_server_run
    virtual int this_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::sockets_server_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_one_run
    virtual int set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::set_accept_one_run(argc, argv, env))) {
            run_ = &derives::this_sockets_server_run;
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_run
    virtual int set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::set_accept_run(argc, argv, env))) {
            run_ = &derives::this_sockets_server_run;
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_request_run
    virtual int this_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::output_request_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int set_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_output_request_run;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    virtual int this_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::output_response_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int set_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_output_response_run;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual int no_sttp_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::prepare_response_to_request_run(response, \"" << request << "\", argc, argv, env)))...");
        if (!(err = extends::prepare_response_to_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << "= extends::prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::prepare_response_to_request_run(response, \"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool prepared_response = false;
        const char_t* chars = 0; size_t length = 0;
        
        LOGGER_IS_LOGGED_INFO("((chars = request.has_chars(length)))...");
        if ((chars = request.has_chars(length))) {
            output_t& output = this->output();
            const bool old_verbose_output = output.verbose_output(), 
                       verbose_output = this->verbose_output();

            output.set_verbose_output(verbose_output);
            LOGGER_IS_LOGGED_INFO("(!(err = output.on_set_client_hello_option(\"" << chars << "\", " << length << ")))...");
            if (!(err = output.on_set_client_hello_option(chars, length))) {
                string_t& content_string = this->content_string();
                string_output_t string_output(content_string);
                output_to_t* old_output = output.set_output_to(&string_output);

                content_string.clear();
                LOGGER_IS_LOGGED_INFO("(!(err = output.output_client_hello_messages()))...");
                if (!(err = output.output_client_hello_messages())) {

                    LOGGER_IS_LOGGED_INFO("(chars = content_string.has_chars(" << length << "))...");
                    if ((chars = content_string.has_chars(length))) {
                        const string_t& endof_content_string = this->endof_content_string();
                        LOGGER_IS_LOGGED_INFO("response.assign(\"" << chars << "\", " << length << ")...");
                        response.assign(chars, length);
                        LOGGER_IS_LOGGED_INFO("response.append(\"" << endof_content_string << "\")...");
                        response.append(endof_content_string);
                        prepared_response = true;
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (chars = content_string.has_chars(" << length << "))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = output.output_client_hello_messages()))");
                }
                output.set_output_to(old_output);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = output.on_set_client_hello_option(\"" << chars << "\", " << length << ")))");
            }
            output.set_verbose_output(old_verbose_output);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = request.has_chars(" << length << ")))");
        }
        if (!(prepared_response)) {
            LOGGER_IS_LOGGED_INFO("(!(err = no_sttp_prepare_response_to_request_run(response, \"" << request << "\", argc, argv, env)))...");
            if (!(err = no_sttp_prepare_response_to_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << "= no_sttp_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = no_sttp_prepare_response_to_request_run(response, \"" << request << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace server 
} /// namespace sttp 
} /// namespace protocol 
} /// namespace sockets 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_STTP_SERVER_MAIN_HPP
