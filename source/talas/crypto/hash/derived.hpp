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
///   File: derived.hpp
///
/// Author: $author$
///   Date: 9/22/2025
//////////////////////////////////////////////////////////////////////////
#ifndef TALAS_CRYPTO_HASH_DERIVED_HPP
#define TALAS_CRYPTO_HASH_DERIVED_HPP

#include "talas/crypto/hash/base.hpp"

#define TALAS_CRYPTO_HASH_DERIVED_NAME "derived"

namespace talas {
namespace crypto {
namespace hash {

typedef base_implements derived_implements;
typedef base derived_extends;
///////////////////////////////////////////////////////////////////////
///  Class: derivedt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = derived_implements, class TExtends = derived_extends>

class _EXPORT_CLASS derivedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    enum {
        HASHSIZE  = 2048,
        BLOCKSIZE = HASHSIZE,
        KEYMIN    = 1,
        KEYMAX    = BLOCKSIZE,
        KEYSIZE   = BLOCKSIZE
    };
    enum {
        HASH_SIZE = HASHSIZE,
        KEY_MIN = KEYMIN,
        KEY_MAX = KEYMAX,
        KEY_SIZE = KEYSIZE
    };

    ///////////////////////////////////////////////////////////////////////
    /// class implement
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS implement: virtual public talas::crypto::implement_base {
    public:
        typedef talas::crypto::implement_base Implements;
        typedef implement Derives;
    
        ///////////////////////////////////////////////////////////////////////
        /// constructor / destructor
        ///////////////////////////////////////////////////////////////////////
        implement() {
        }
        virtual ~implement() {
        }
    private:
        implement(const implement& copy) {
        }
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void initial() {
        }
        virtual void final() {
        }
        virtual void transform() {
        }
        virtual void update(const uint8_t* in, size_t inlen) {
        }
        virtual void assign(derivedt &derived, const uint8_t* in, size_t inlen) {
            derived.assign(in, inlen);
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
    }; /// class implement

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    derivedt(void* out, size_t outsize, const void* in, size_t inlen)
    : Extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator~();
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            error e = error_failed;
            throw (e);
        }
    }
    derivedt(const derivedt& copy)
    : Extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator=(copy);
    }
    derivedt(implement &p_implement)
    : Extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash),
      m_implement(&p_implement) {
        this->operator~();
    }
    derivedt()
    : Extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator~();
    }
    virtual ~derivedt() {
        this->operator~();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual derivedt& operator = (const derivedt& copy) {
        memcpy(m_in, copy.m_in, sizeof(m_in));
        memcpy(m_key, copy.m_key, sizeof(m_key));
        memcpy(m_mac, copy.m_mac, sizeof(m_mac));
        memcpy(m_hash, copy.m_hash, sizeof(m_hash));
        return *this;
    }
    virtual derivedt& operator ~ () {
        memset(m_in, 0, sizeof(m_in));
        memset(m_key, 0, sizeof(m_key));
        memset(m_mac, 0, sizeof(m_mac));
        memset(m_hash, 0, sizeof(m_hash));
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* name() const {
        return TALAS_CRYPTO_HASH_DERIVED_NAME;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void initial() {
        if ((m_implement)) {
            m_implement->initial();
        } else {}
    }
    virtual void final() {
        if ((m_implement)) {
            m_implement->final();
        } else {}
    }
    virtual void transform() {
        if ((m_implement)) {
            m_implement->transform();
        } else {}
    }
    virtual void update(const uint8_t* in, size_t inlen) {
        if ((m_implement)) {
            m_implement->update(in, inlen);
        } else {}
    }
    virtual void assign(const uint8_t* in, size_t inlen) {
        if ((0 != (in)) && (0 < (inlen))) {
            if (HASHSIZE < (inlen)) {
                inlen = HASHSIZE;
            } else {}
            memset(m_hash, 0, HASHSIZE);
            memcpy(m_hash, in, inlen);
        }
    }
    virtual bool encoded() const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    implement *m_implement;
    uint8_t m_hash[HASHSIZE];
    uint8_t m_in[BLOCKSIZE];
    uint8_t m_key[BLOCKSIZE];
    uint8_t m_mac[HASHSIZE];
};
typedef derivedt<> derived;

} /// namespace hash 
} /// namespace crypto 
} /// namespace talas 

#endif /// ndef TALAS_CRYPTO_HASH_DERIVED_HPP
