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
///   Date: 8/12/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_HPP
#define TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_HPP

#include "talas/app/console/network/server/main_opt.hpp"

namespace talas {
namespace app {
namespace console {
namespace network {
namespace server {

///////////////////////////////////////////////////////////////////////
/// class maint
///////////////////////////////////////////////////////////////////////
template <class TExtends = server::main_opt, class TImplements = typename TExtends::Implements>
class EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    typedef typename TExtends::writer_t writer_t;
    typedef typename TExtends::reader_t reader_t;
    typedef typename TExtends::string_t string_t;
    typedef typename TExtends::char_t char_t;
    
    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): Extends(copy) {
    }

protected:
    typedef typename TExtends::socket_t socket_t;
    typedef typename TExtends::socket_reader_t socket_reader_t;
    typedef typename TExtends::socket_writer_t socket_writer_t;
    typedef typename TExtends::sized_reader_t sized_reader_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int server_sockets_run(socket_t& socket, int argc, char_t** argv, char_t** env) {
        string_t& request = this->request();
        int err = 0;

        if (!(err = all_recv_request(request, socket, argc, argv, env))) {

            if (!(err = all_on_recv_request(request, socket, argc, argv, env))) {
                string_t& response = this->response();
                
                if (!(err = all_send_response(socket, response, argc, argv, env))) {
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        socket_reader_t reader(socket);
        
        if (!(err = all_on_recv_request(request, reader, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_on_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_recv_request(request, socket, argc, argv, env))) {
            int err2 = 0;
            err = on_recv_request(request, socket, argc, argv, env);
            if ((err2 = after_on_recv_request(request, socket, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_recv_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = all_on_process_request(request, argc, argv, env))) {
            char_t* content = 0; size_t content_size = 0;

            if ((content = this->content(content_size))) {
                string_t& content_type = this->content_type();
                size_t content_length = 0;
                ssize_t amount = 0;
                
                if ((0 < (content_length = this->content_length()))) {
                    sized_reader_t content_reader(reader, content_length);
                    
                    err = all_on_recv_request_content
                    (content, content_size, content_length, content_type, content_reader, argc, argv, env);
                } else {
                    const char_t* chars = 0; size_t length = 0;

                    if ((chars = content_type.has_chars(length))) {
                        err = all_on_recv_request_content
                        (content, content_size, content_length, content_type, reader, argc, argv, env);
                    }
                }
            }
        }
        return err;
    }
    virtual int before_on_recv_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_recv_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_recv_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_recv_request(request, reader, argc, argv, env))) {
            int err2 = 0;
            err = on_recv_request(request, reader, argc, argv, env);
            if ((err2 = after_on_recv_request(request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_recv_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_type, reader_t& content_reader, int argc, char_t** argv, char_t** env) {
        int err = 0;

        if ((content) && (content_size)) {
            string_t& content_encoding = this->content_encoding();
            size_t length = 0;
            ssize_t amount = 0;

            for (length = 0; (0 < (amount = content_reader.read(content, content_size))); length += amount) {
                if ((err = all_on_process_request_content
                     (content, amount, content_length, content_encoding, content_type, argc, argv, env))) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int before_on_recv_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_type, reader_t& content_reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_recv_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_type, reader_t& content_reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_recv_request_content(char_t* content, size_t content_size, size_t content_length, string_t& content_type, reader_t& content_reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_recv_request_content(content, content_size, content_length, content_type, content_reader, argc, argv, env))) {
            int err2 = 0;
            err = on_recv_request_content(content, content_size, content_length, content_type, content_reader, argc, argv, env);
            if ((err2 = after_on_recv_request_content(content, content_size, content_length, content_type, content_reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_process_request(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        
        if ((chars = request.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_on_process_request(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_process_request(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_process_request(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_process_request(request, argc, argv, env))) {
            int err2 = 0;
            err = on_process_request(request, argc, argv, env);
            if ((err2 = after_on_process_request(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_process_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_encoding, string_t& content_type, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((content) && (content_size)) {
            this->outln(content, content_size);
        }
        return err;
    }
    virtual int before_on_process_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_encoding, string_t& content_type, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_process_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_encoding, string_t& content_type, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_process_request_content
    (char_t* content, size_t content_size, size_t content_length, 
     string_t& content_encoding, string_t& content_type, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_process_request_content(content, content_size, content_length, content_encoding, content_type, argc, argv, env))) {
            int err2 = 0;
            err = on_process_request_content(content, content_size, content_length, content_encoding, content_type, argc, argv, env);
            if ((err2 = after_on_process_request_content(content, content_size, content_length, content_encoding, content_type, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        socket_reader_t reader(socket);
        int err = 0;
        
        if (!(err = all_read_request(request, reader, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_request(string_t& request, socket_t& socket, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_request(request, socket, argc, argv, env))) {
            int err2 = 0;
            err = recv_request(request, socket, argc, argv, env);
            if ((err2 = after_recv_request(request, socket, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int read_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        char_t* chars = 0; size_t size = 0;
        int err = 0;
        
        if ((chars = this->recved(size)) && (size)) {
            ssize_t amount = 0, count = 0;
            string_t request_line;

            TALAS_LOG_DEBUG("reader.read_crlf(chars, size = " << size << "))...");
            if (0 < (amount = reader.read_crlf(chars, size))) {

                request_line.assign(chars, amount);
                TALAS_LOG_DEBUG("..." << amount << " = reader.read_crlf(chars = \"" << request_line << "\", size = " << size << "))...");
                if (!(err = all_on_read_request_line(request, request_line, reader, argc, argv, env))) {
                    while (2 < amount) {

                        TALAS_LOG_DEBUG("reader.read_crlf(chars, size = " << size << "))...");
                        if (0 < (amount = reader.read_crlf(chars, size))) {
            
                            request_line.assign(chars, amount);
                            TALAS_LOG_DEBUG("..." << amount << " = reader.read_crlf(chars = \"" << request_line << "\", size = " << size << "))...");
                            if ((err = all_on_read_request_header(request, request_line, reader, argc, argv, env))) {
                                break;
                            }
                        } else {
                            TALAS_LOG_ERROR("...failed" << amount << " = reader.read_crlf(chars, size = " << size << "))...");
                            err = 1;
                        }
                    }
                }
            } else {
                TALAS_LOG_ERROR("...failed" << amount << " = reader.read_crlf(chars, size = " << size << "))...");
                err = 1;
            }
        } else {
            err = 1;
        }
        return err;
    }
    virtual int before_read_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_request(string_t& request, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_read_request(request, reader, argc, argv, env))) {
            int err2 = 0;
            err = read_request(request, reader, argc, argv, env);
            if ((err2 = after_read_request(request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_read_request_line(string_t& request, string_t& request_line, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        request.assign(request_line);
        return err;
    }
    virtual int before_on_read_request_line(string_t& request, string_t& request_line, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_read_request_line(string_t& request, string_t& request_line, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_read_request_line(string_t& request, string_t& request_line, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_read_request_line(request, request_line, reader, argc, argv, env))) {
            int err2 = 0;
            err = on_read_request_line(request, request_line, reader, argc, argv, env);
            if ((err2 = after_on_read_request_line(request, request_line, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_read_request_header(string_t& request, string_t& request_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        request.append(request_header);
        if (!(err = this->all_on_read_message_header(request, request_header, reader, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_on_read_request_header(string_t& request, string_t& request_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_on_read_request_header(string_t& request, string_t& request_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_on_read_request_header(string_t& request, string_t& request_header, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_on_read_request_header(request, request_header, reader, argc, argv, env))) {
            int err2 = 0;
            err = on_read_request_header(request, request_header, reader, argc, argv, env);
            if ((err2 = after_on_read_request_header(request, request_header, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int send_response(socket_t& socket, string_t& response, int argc, char_t** argv, char_t** env) {
        socket_writer_t writer(socket);
        int err = 0;
        
        if (!(err = all_write_response(writer, response, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_send_response(socket_t& socket, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response(socket_t& socket, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response(socket_t& socket, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response(socket, response, argc, argv, env))) {
            int err2 = 0;
            err = send_response(socket, response, argc, argv, env);
            if ((err2 = after_send_response(socket, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int write_response(writer_t& writer, string_t& response, int argc, char_t** argv, char_t** env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;

        if ((chars = response.has_chars(length))) {
            ssize_t count = 0;

            TALAS_LOG_DEBUG("writer.write(chars = \"" << chars << "\", length = " << length << ")...");
            if (((ssize_t)length) != (count = writer.write(chars, length))) {
                TALAS_LOG_ERROR("...failed " << count << " = writer.write(chars = \"" << chars << "\", length = " << length << ")...");
            } else {
                TALAS_LOG_DEBUG("..." << count << " = writer.write(chars = \"" << chars << "\", length = " << length << ")");
            }
        }
        return err;
    }
    virtual int before_write_response(writer_t& writer, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_response(writer_t& writer, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_response(writer_t& writer, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_write_response(writer, response, argc, argv, env))) {
            int err2 = 0;
            err = write_response(writer, response, argc, argv, env);
            if ((err2 = after_write_response(writer, response, argc, argv, env))) {
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

} /// namespace server 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace talas 

#endif /// ndef TALAS_APP_CONSOLE_NETWORK_SERVER_MAIN_HPP 