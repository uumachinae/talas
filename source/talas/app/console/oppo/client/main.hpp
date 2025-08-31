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
///   Date: 8/16/2021
///////////////////////////////////////////////////////////////////////
#ifndef TALAS_APP_CONSOLE_OPPO_CLIENT_MAIN_HPP
#define TALAS_APP_CONSOLE_OPPO_CLIENT_MAIN_HPP

#include "talas/app/console/oppo/client/main_opt.hpp"

namespace talas {
namespace app {
namespace console {
namespace oppo {
namespace client {

///////////////////////////////////////////////////////////////////////
/// class maint
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::Implements>

class EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    typedef typename Extends::char_t char_t;
    typedef typename Extends::string_t string_t;
    typedef typename Extends::reader_t reader_t;
    typedef typename Extends::writer_t writer_t;
    typedef typename Extends::file_t file_t;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    maint()
    : volume_up_("VUP"), volume_down_("VDN"), volume_level_("SVL"), volume_("QVL"),
      next_track_("NXT"), prev_track_("PRE"), track_("QTK"),
      start_play_("PLA"), stop_play_("STP"), 
      replay_all_("SRP ALL"), replay_rand_("SRP RND"), replay_("SRP"),
      bray_input_("SIS 0"), hdmi_input_("SIS 1"), 
      eject_open_("EJT OPEN"), eject_close_("EJT CLOSE"), eject_("EJT"), 
      power_on_("POW ON"), power_off_("POW OFF"), power_("POW"),
      request_(power_), 
      port_(TALAS_APP_CONSOLE_OPPO_CLIENT_PORT) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename Extends::in_reader_t in_reader_t;
    typedef typename Extends::out_writer_t out_writer_t;
    typedef typename Extends::err_writer_t err_writer_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*before_write_request_)(writer_t& writer, string_t& request, int argc, char_t** argv, char_t** env);
    virtual int before_write_request(writer_t& writer, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (before_write_request_) {
            LOGGER_LOG_INFO("(!(err = (this->*before_write_request_)(writer, request, argc, argv, env)))...");
            if (!(err = (this->*before_write_request_)(writer, request, argc, argv, env))) {
                LOGGER_LOG_INFO("...(!(" << err << " = (this->*before_write_request_)(writer, request, argc, argv, env)))");
            } else {
                LOGGER_LOG_INFO("...failed on (!(" << err << " = (this->*before_write_request_)(writer, request, argc, argv, env)))");
            }
        } else {
            LOGGER_LOG_INFO("(!(err = append_before_write_request(writer, request, argc, argv, env)))...");
            if (!(err = append_before_write_request(writer, request, argc, argv, env))) {
                LOGGER_LOG_INFO("...(!(" << err << " = append_before_write_request(writer, request, argc, argv, env)))");
            } else {
                LOGGER_LOG_INFO("...failed on(!(" << err << " = append_before_write_request(writer, request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int append_before_write_request(writer_t& writer, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        request.assign("#");
        request.append(request_);
        request.append("\r\n");
        return err;
    }
    virtual int no_append_before_write_request(writer_t& writer, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        request.assign(request_);
        request.append("\r\n");
        return err;
    }
    virtual int set_no_append_before_write_request(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_write_request_ = &Derives::no_append_before_write_request;
        return err;
    }
    virtual int no_append_before_write_request_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_no_append_before_write_request(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_write_request_ = 0;
        return err;
    }
    virtual int no_append_before_write_request_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_next_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(next_track_);
        return err;
    }
    virtual int on_prev_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(prev_track_);
        return err;
    }
    virtual int on_track_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(track_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_start_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(start_play_);
        return err;
    }
    virtual int on_stop_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(stop_play_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_volume_up_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(volume_up_);
        return err;
    }
    virtual int on_volume_down_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(volume_down_);
        return err;
    }
    virtual int on_volume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(volume_level_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_replay_all_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(replay_all_);
        return err;
    }
    virtual int on_replay_random_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(replay_rand_);
        return err;
    }
    virtual int on_replay_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(replay_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_bray_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(bray_input_);
        return err;
    }
    virtual int on_hdmi_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(hdmi_input_);
        return err;
    }
    virtual int on_eject_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(eject_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_power_on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(power_on_);
        return err;
    }
    virtual int on_power_off_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(power_off_);
        return err;
    }
    virtual int on_power_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        request_.assign(power_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((argind < argc) && (arg) && (arg[0])) {
            request_.assign(arg);
            err = set_no_append_before_write_request(argc, argv, env);
        }
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
    string_t volume_up_, volume_down_, volume_level_, volume_, next_track_, prev_track_, track_,
             start_play_, stop_play_, replay_all_, replay_rand_, replay_,
             bray_input_, hdmi_input_, eject_open_, eject_close_, eject_,             
             power_on_, power_off_, power_, request_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace oppo
} /// namespace console
} /// namespace app
} /// namespace talas

#endif /// ndef TALAS_APP_CONSOLE_OPPO_CLIENT_MAIN_HPP
