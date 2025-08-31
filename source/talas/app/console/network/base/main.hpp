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
///   File: main.hpp
///
/// Author: $author$
///   Date: 2/14/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP

#include "talas/app/console/network/base/main_opt.hpp"
#include "talas/io/socket/reader.hpp"
#include "talas/io/socket/writer.hpp"

#if !defined (TALAS_APP_CONSOLE_NETWORK_REQUEST)
#define TALAS_APP_CONSOLE_NETWORK_REQUEST \
    "GET / HTTP/1.0\r\n" \
    "Host:localhost\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:5\r\n" \
    "\r\nGet\r\n"
#endif /// !defined (TALAS_APP_CONSOLE_NETWORK_REQUEST)

#if !defined (TALAS_APP_CONSOLE_NETWORK_RESPONSE)
#define TALAS_APP_CONSOLE_NETWORK_RESPONSE \
    "HTTP/1.0 200 OK\r\n" \
    "Host:localhost\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:4\r\n" \
    "\r\nOk\r\n"
#endif /// !defined (TALAS_APP_CONSOLE_NETWORK_RESPONSE)

#if !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RECVED_SIZE)
#define TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RECVED_SIZE 2048
#endif /// !defined(TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RECVED_SIZE)

namespace talas {
namespace app {
namespace console {
namespace network {
namespace base {

///////////////////////////////////////////////////////////////////////
/// class maint
///////////////////////////////////////////////////////////////////////
template <class TExtends = main_opt, class TImplements = typename TExtends::Implements>
class EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    typedef typename TExtends::char_t char_t;
    typedef typename TExtends::string_t string_t;
    typedef typename TExtends::reader_t reader_t;
    typedef typename TExtends::writer_t writer_t;
    
    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    maint()
    : request_(TALAS_APP_CONSOLE_NETWORK_REQUEST), 
      response_(TALAS_APP_CONSOLE_NETWORK_RESPONSE), 
      content_length_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): Extends(copy) {
    }

protected:
    typedef typename TExtends::socket_t socket_t;
    typedef talas::io::socket::readert<reader_t, socket_t> socket_reader_t;
    typedef talas::io::socket::writert<writer_t, socket_t> socket_writer_t;
    typedef talas::io::sized::readert<reader_t> sized_reader_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->all_plain_sockets_run(argc, argv, env);
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        TALAS_LOG_DEBUG("talas::network::os::sockets::startup()...");
        if (!(talas::network::os::sockets::startup())) {
            TALAS_LOG_ERROR("...failed on talas::network::os::sockets::startup()");
            err = 1;
        }
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        TALAS_LOG_DEBUG("talas::network::os::sockets::cleanup()...");
        if (!(talas::network::os::sockets::cleanup())) {
            TALAS_LOG_ERROR("...failed on talas::network::os::sockets::cleanup()");
            err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int plain_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_plain_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_plain_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_plain_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->before_plain_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = this->plain_sockets_run(argc, argv, env);
            if ((err2 = this->after_plain_sockets_run(argc, argv, env))) {
                if (!(err)) {
                    err = err2;
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t request_;
    virtual string_t& set_request(const char_t* to, size_t length) {
        string_t& request = this->request();
        request.assign(to, length);
        return request;
    }
    virtual string_t& set_request(const char_t* to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const string_t& to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& request() const {
        return (string_t&)request_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t response_;
    virtual string_t& set_response(const char_t* to, size_t length) {
        string_t& response = this->response();
        response.assign(to, length);
        return response;
    }
    virtual string_t& set_response(const char_t* to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response(const string_t& to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& response() const {
        return (string_t&)response_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t content_type_;
    virtual string_t& set_content_type(const char_t* to, size_t length) {
        string_t& content_type = this->content_type();
        const string_t to_s(to, length);
        set_content_type(to_s);
        return content_type;
    }
    virtual string_t& set_content_type(const char_t* to) {
        string_t& content_type = this->content_type();
        const string_t to_s(to);
        set_content_type(to_s);
        return content_type;
    }
    virtual string_t& set_content_type(const string_t& to) {
        string_t& content_type = this->content_type();
        TALAS_LOG_DEBUG("...content_type.assign(\"" << to << "\")...");
        content_type.assign(to);
        return content_type;
    }
    virtual string_t& content_type() const {
        return (string_t&)content_type_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    string_t content_encoding_;
    virtual string_t& set_content_encoding(const char_t* to, size_t length) {
        string_t& content_encoding = this->content_encoding();
        const string_t to_s(to, length);
        set_content_encoding(to_s);
        return content_encoding;
    }
    virtual string_t& set_content_encoding(const char_t* to) {
        string_t& content_encoding = this->content_encoding();
        const string_t to_s(to);
        set_content_encoding(to_s);
        return content_encoding;
    }
    virtual string_t& set_content_encoding(const string_t& to) {
        string_t& content_encoding = this->content_encoding();
        TALAS_LOG_DEBUG("...content_encoding.assign(\"" << to << "\")...");
        content_encoding.assign(to);
        return content_encoding;
    }
    virtual string_t& content_encoding() const {
        return (string_t&)content_encoding_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ssize_t content_length_;
    virtual size_t& set_content_length(const char_t* to, size_t length) {
        size_t& content_length = this->content_length();
        const string_t to_s(to, length);
        set_content_length(to_s);
        return content_length;
    }
    virtual size_t& set_content_length(const char_t* to) {
        size_t& content_length = this->content_length();
        const string_t to_s(to);
        set_content_length(to_s);
        return content_length;
    }
    virtual size_t& set_content_length(const string_t& to) {
        size_t& content_length = this->content_length();
        unsigned length = 0;
        if (0 < (length = to.to_unsigned())) {
            TALAS_LOG_DEBUG("...content_length = " << length << "...");
            content_length = length;
        }
        return content_length;
    }
    virtual size_t& content_length() const {
        return (size_t&)content_length_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const string_t& content_type_message_header_name() const {
        static const string_t header_name("Content-Type");
        return header_name;
    }
    virtual const string_t& content_length_message_header_name() const {
        static const string_t header_name("Content-Length");
        return header_name;
    }
    virtual const string_t& content_encoding_message_header_name() const {
        static const string_t header_name("Content-Encoding");
        return header_name;
    }
    virtual const char_t message_header_name_separator() const {
        return (const char_t)':';
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_t content_[TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RECVED_SIZE];
    virtual char_t* content(size_t& size) const {
        size = sizeof(content_);
        return (char_t*)content_;
    }
    char_t recved_[TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_RECVED_SIZE];
    virtual char_t* recved(size_t& size) const {
        size = sizeof(recved_);
        return (char_t*)recved_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_process_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        
        if ((chars = message.has_chars(length))) {
            size_t content_length = 0, content_size = 0;
            char_t* content = 0;

            this->outln(chars, length);
            if ((0 < (content_length = this->content_length())) && (content = this->content(content_size))) {
                socket_reader_t socket_reader(socket);
                sized_reader_t content_reader(socket_reader, content_length);
                ssize_t amount = 0;
                
                for (length = 0; (0 < (amount = content_reader.read(content, content_size))); length += amount) {
                    this->outln(content, amount);
                }
            }
        }
        return err;
    }
    virtual int before_on_process_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_process_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_process_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_process_message(message, socket, argc, argv, env))) {
            int err2 = 0;
            err = on_process_message(message, socket, argc, argv, env);
            if ((err2 = after_on_process_message(message, socket, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_recv_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_on_process_message(message, socket, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_on_recv_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_recv_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_recv_message(string_t& message, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_recv_message(message, socket, argc, argv, env))) {
            int err2 = 0;
            err = on_recv_message(message, socket, argc, argv, env);
            if ((err2 = after_on_recv_message(message, socket, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_read_message_header(string_t& message, string_t& message_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;

        if ((chars = message_header.has_chars(length))) {
            char_t c = 0, name_separator = this->message_header_name_separator();
            string_t name, value;

            for (size_t i = 0; i < length; ++i) {

                if ((name_separator == (c = chars[i]))) {
                    if (0 < (i)) { 
                        const char_t sp = ((const char_t)' ');

                        name.assign(chars, i);
                        for (++i; i < length; ++i) {

                            if (sp != (c = chars[i])) {
                                const char_t cr = ((const char_t)'\r');
 
                                for (size_t j = i+1; j < length; ++j) {
                                    if (!(cr != (c = chars[j]))) {
                                        length = j;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        if ((i < length)) {
                            value.assign(chars+i, length-i);
                        }
                        err = all_on_read_message_header_fields(name, value, argc, argv, env);
                    } else {
                        err = 1;
                    }
                    break;
                }
            }
        }
        return err;
    }
    virtual int before_on_read_message_header(string_t& message, string_t& message_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_read_message_header(string_t& message, string_t& message_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_read_message_header(string_t& message, string_t& message_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_read_message_header(message, message_header, reader, argc, argv, env))) {
            int err2 = 0;
            err = on_read_message_header(message, message_header, reader, argc, argv, env);
            if ((err2 = after_on_read_message_header(message, message_header, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_read_message_header_fields(string_t& name, string_t& value, int argc, char_t** argv, char_t** env) {
        const string_t& content_length_message_header_name = this->content_length_message_header_name();
        int err = 0, unequal = 0;

        if (!(unequal = name.compare(content_length_message_header_name))) {
            this->set_content_length(value);
        } else {
            const string_t& content_type_message_header_name = this->content_type_message_header_name();

            if (!(unequal = name.compare(content_type_message_header_name))) {
                this->set_content_type(value);
            } else {
            }
        }
        return err;
    }
    virtual int before_on_read_message_header_fields(string_t& name, string_t& value, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_read_message_header_fields(string_t& name, string_t& value, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_read_message_header_fields(string_t& name, string_t& value, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_read_message_header_fields(name, value, argc, argv, env))) {
            int err2 = 0;
            err = on_read_message_header_fields(name, value, argc, argv, env);
            if ((err2 = after_on_read_message_header_fields(name, value, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
}; /// class maint
typedef maint<> main;

} /// namespace base 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace talas 

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP 