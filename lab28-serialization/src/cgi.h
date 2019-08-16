#ifndef MESA_LAB28_CGI_H
#define MESA_LAB28_CGI_H

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

// A type to store Common Gateway Interface (CGI)
// keys and values.
struct cgi {
    std::map<std::string, std::string> kvp;
    cgi() = default;
    ~cgi() = default;
    explicit cgi(const std::string& name, 
                 const std::string& value)
        {
            kvp.emplace(name, value); 
        }

    cgi (const cgi& other) = default;
    cgi& operator=(const cgi& other) = default;

    // validate the QUERY_STRING variable
    // set in the local environment.
    //
    // If valid, call parse.
    //
    // Return the size of the kvp map.
    size_t read();

    // Split the QUERY_STRING into key-value pairs
    // and fill kvp.
    //
    // Return the size of the kvp map.
    size_t parse(const std::string& qs);
};

inline
bool operator==(const cgi& x, const cgi& y) {
    return x.kvp == y.kvp;
}
inline
bool operator!=(const cgi& x, const cgi& y) {
    return !(x == y);
}
inline
bool operator<(const cgi& x, const cgi& y) { 
    return x.kvp < y.kvp;
}
inline
bool operator>(const cgi& x, const cgi& y) {
    return y < x;
}
inline
bool operator<=(const cgi& x, const cgi& y) {
    return !(y < x);
}
inline
bool operator>=(const cgi& x, const cgi& y) {
    return !(x < y);
} 

inline
std::ostream& operator<<(std::ostream& os, const cgi& rhs) {
    for (const auto& pair: rhs.kvp) {
        os << pair.first << " = " << pair.second << '\n';
    }
    return os;
}

#endif

