#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <algorithm>
#include <stdexcept>
namespace EnvParser {
    class data {
    public:
        data(std::string data):value(data){}
        
        ~data(){}
        
        // delete copy constructor
        data(const data &) = delete;
        data operator = (const data &) = delete;
        
        // delete move constructor
        data(data &&) = delete;
        data operator = (data &&) = delete;
        
        // Type casting operator overloads
        
        inline operator int()const 
        {
            return std::stoi(value);
        }
        
        inline operator float()const 
        {
            return std::stof(value);
        }
        
        inline operator double()const {
            return std::stod(value);
        }
        
        inline operator bool()const 
        {
            auto lower_data = data::to_lower(value);
            if(lower_data == "0" || lower_data == "false")
                return false;
            else if(lower_data == "1" || lower_data == "true" )
                return true;
            else
                throw std::runtime_error("Input does not support conversion to boolean !");
        }
        
        static inline std::string to_lower(std::string value) {
            std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {return std::tolower(c);});
            return value;
        }
        
        std::string value;
    };
}

#endif
