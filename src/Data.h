#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <algorithm>
#include <stdexcept>
namespace EnvParser {
    class Data {
    public:
        Data(std::string data):data(data){}
        
        ~Data(){}
        
        // delete copy constructor
        Data(const Data &) = delete;
        Data operator = (const Data &) = delete;
        
        // delete move constructor
        Data(Data &&) = delete;
        Data operator = (Data &&) = delete;
        
        // Type casting operator overloads
        
        inline operator int()const 
        {
            return std::stoi(data);
        }
        
        inline operator float()const 
        {
            return std::stof(data);
        }
        
        inline operator double()const {
            return std::stod(data);
        }
        
        inline operator bool()const 
        {
            auto lower_data = Data::to_lower(data);
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
        
        std::string data;
    };
}

#endif
