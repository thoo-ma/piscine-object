#include <string>
#include <ostream>

class ILogger {
public:
    virtual void write(std::string) = 0;
};

class Logger : public ILogger {
    std::ostream & _output;
    std::string _header;
    public:
    Logger(std::ostream & output, std::string const header = "") : _output(output), _header(header) {
        if (!_header.empty()) {
            /// @note timestamp header string ends with a newline
            if (_header[_header.length() - 1] == '\n')
                _header = _header.substr(0, _header.length() - 1);
            _header.append(": ");
        }
    }
    void write(std::string s) override { _output << _header << s << "\n"; }
};

