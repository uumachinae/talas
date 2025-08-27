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
///   Date: 6/21/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_STTP_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_STTP_BASE_MAIN_HPP

#include "xos/app/console/protocol/sttp/base/main_opt.hpp"
#include "xos/protocol/sttp/base/output.hpp"
#include "xos/io/protocol/crypto/output.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace sttp {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::sttp::base::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef xos::protocol::sttp::base::output output_t;
    typedef typename output_t::output_to_t output_to_t;
    typedef typename output_t::output_to_t::string_t output_to_string_t;
    typedef typename output_t::literal_string_t literal_string_t;
    typedef typename output_t::byte_array_t byte_array_t;
    typedef typename output_t::byte_arrays_t byte_arrays_t;
    typedef typename output_t::hex_read_to_byte_array_t hex_read_to_byte_array_t;
    typedef typename output_t::hex_read_to_byte_arrays_t hex_read_to_byte_arrays_t;

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
    /// ...output...key...run
    virtual int default_output_server_rsa_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output(); 
        output.output_server_rsa_key_pair();
        return err;
    }
    virtual int default_output_client_rsa_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output(); 
        output.output_client_rsa_key_pair();
        return err;
    }

    /// ...output_..._secret_run
    virtual int default_output_pseudo_random_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output(); 
        output.output_pseudo_random_secret();
        return err;
    }
    virtual int default_output_pseudo_random_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output(); 
        output.output_pseudo_random_seed();
        return err;
    }
    virtual int default_output_master_secret_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output(); 
        output.output_master_secret_seed();
        return err;
    }
    virtual int default_output_key_expansion_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output(); 
        output.output_key_expansion_seed();
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_hex_run
    virtual int output_hex_run(const byte_array_t &array, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.output_hex(array);
        return err;
    }
    virtual int before_output_hex_run(byte_array_t &array, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_hex_run(byte_array_t &array, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_hex_run(byte_array_t &array, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_hex_run(array, argc, argv, env))) {
            int err2 = 0;
            err = output_hex_run(array, argc, argv, env);
            if ((err2 = after_output_hex_run(array, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...set...text_literal
    virtual int on_set_text_literal(byte_array_t &array, literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_text_literal(array, literal);
        return err;
    }
    virtual int set_string_on_set_text_literal(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_string_on_set_text_literal();
        return err;
    }
    virtual int set_file_on_set_text_literal(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_file_on_set_text_literal();
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...set...hex_literal
    virtual int on_set_hex_literal(byte_array_t &array, literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literal(array, literal);
        return err;
    }
    virtual int set_string_on_set_hex_literal(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_string_on_set_hex_literal();
        return err;
    }
    virtual int set_file_on_set_hex_literal(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_file_on_set_hex_literal();
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...set...hex_literal_arrays
    virtual int on_set_hex_literal_arrays(byte_arrays_t &arrays, literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literal_arrays(arrays, literal);
        return err;
    }
    virtual int set_string_on_set_hex_literal_arrays(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_string_on_set_hex_literal_arrays();
        return err;
    }
    virtual int set_file_on_set_hex_literal_arrays(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_file_on_set_hex_literal_arrays();
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...set...hex_literals
    virtual int on_set_hex_literals
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int set_string_on_set_hex_literals(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_string_on_set_hex_literals();
        return err;
    }
    virtual int set_file_on_set_hex_literals(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.set_file_on_set_hex_literals();
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// set...on_set_hex_literals
    virtual int set_file_on_set_literals() {
        int err = 0;
        output_t& output = this->output();
        output.set_file_on_set_literals();
        return err;
    }
    virtual int set_string_on_set_literals() {
        int err = 0;
        output_t& output = this->output();
        output.set_string_on_set_literals();
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on_set_hex_literals
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(a1, a2, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, byte_array_t &a3, 
     literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(a1, a2, a3, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, 
     literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(a1, a2, a3, a4, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, byte_array_t &a5, 
     literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(a1, a2, a3, a4, a5, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, 
     byte_array_t &a5, byte_array_t &a6, 
     literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(a1, a2, a3, a4, a5, a6, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, 
     byte_array_t &a5, byte_array_t &a6, byte_array_t &a7, 
     literal_string_t &literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_t& output = this->output();
        output.on_set_hex_literals(a1, a2, a3, a4, a5, a6, a7, literal);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...file_input_option...
    virtual int on_set_file_input_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::on_set_file_input_option_on(optarg, optind, argc, argv, env)))...");
        if (!(err = extends::on_set_file_input_option_on(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("set_file_on_set_literals()...");
            set_file_on_set_literals();
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = extends::on_set_file_input_option_on(optarg, optind, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...string_input_option...
    virtual int on_set_string_input_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::on_set_string_input_option_on(optarg, optind, argc, argv, env)))...");
        if (!(err = extends::on_set_string_input_option_on(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("set_string_on_set_literals()...");
            set_string_on_set_literals();
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = extends::on_set_string_input_option_on(optarg, optind, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual output_t& output() const {
        return (output_t&)output_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    output_t output_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace sttp 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_STTP_BASE_MAIN_HPP
