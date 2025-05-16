#include "immstring.hpp"

// Functions from <cstring> may be used to ease working with 
// null-terminated strings.
// Further reference: https://en.cppreference.com/w/cpp/header/cstring
#include <cstring>

// This header contains std::copy_n for copying sequences of data.
// Further reference: https://en.cppreference.com/w/cpp/header/algorithm
#include <algorithm>

namespace Util {
    // NOTE: Compiler errors related to this constructor provide hints to
    //        where else you need to use `const`.
    ImmutableString::ImmutableString(ImmutableString const &other)
        : m_size{other.size()}, // Order of initialization is important here!
          m_data{new char[m_size + 1]} {
        // Note: The string consists of `m_size` characters and is terminated by a
        //       `\x0` character, thus: `m_size+1`.
        std::copy_n(other.c_str(), m_size + 1, m_data);
    }

    ImmutableString::ImmutableString(char const *src)
        : m_size{(int) std::strlen(src)},
          m_data{new char[m_size + 1]} {
        std::strncpy(m_data, src, m_size + 1); // nur möglich, weil m_data nicht char const...
    }

    ImmutableString ImmutableString::concat(ImmutableString const &other) const {
        if (this->c_str() == nullptr || this->size() == 0) return other;
        if (other.c_str() == nullptr || other.size() == 0) return ImmutableString{this->c_str()};

        int const newSize = this->size() + other.size();
        char *const newChar = new char[newSize + 1];

        std::strncpy(newChar, this->c_str(), this->size() + 1);
        std::strncat(newChar, other.c_str(), other.size() + 1);

        return ImmutableString {newChar, newSize}; // kein Leak, da Destruktor Speicher am Ende freigibt
    }

    ImmutableString::~ImmutableString() {
        delete[] m_data;
    }

    ImmutableString::ImmutableString(char *const buf, int const len) // Parameter entsprechen Instanzvariablentypen
        : m_size{len},
          m_data{buf} {
    }
} // Util
