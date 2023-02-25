#ifndef ENV_H_
#define ENV_H_

#include <filesystem>
#include <sstream>
#include <fstream>
#include <functional>
#include <locale>
#include <algorithm>
#include <string>
#include <map>
#include <memory>
#include "data.h"
#include <iostream>
namespace EnvParser {
    class env {
    public:
        env(){
            parse();
        }
        
        env(std::string file_path) {
            if(!is_env(file_path))
                throw std::runtime_error("Provided file does not env file");
            if(!std::filesystem::exists(file_path))
                throw std::runtime_error("Provided .env file does not exists");
            env::path = file_path;
            parse();

        }
        
        // delete copy constructor
        env(const env &) = delete;
        env operator = (const env &) = delete;
        
        // delete
        env(env &&) = delete;
        env operator = (env &&) = delete;
        
        
        const std::map<std::string, std::unique_ptr<data>> &get_all()const {
            return env::datas;
        }
        
        std::string &operator[](std::string key) {
            
            
        }
        static std::string path;
        static std::map<std::string, std::unique_ptr<data>>  datas;
    private:
        inline bool is_env(std::string env_path) {
         std::filesystem::path file_path = env_path;
         return file_path.extension() == ".env";
        }
        
        void parse() {
            std::cout <<"YES"<<std::endl;
            std::ifstream file(path);
            if(!file.is_open())
                throw std::runtime_error("File can not open");
            std::string line;
            
            auto delete_space = [](std::string line) {
                line.erase(std::remove_if(line.begin(), line.end(), std::bind(std::isspace<char>, std::placeholders::_1, std::locale::classic())), line.end());
                return line;
            };
            
            while(std::getline(file, line)) {
                if(line.empty())
                    continue;
                
                std::string filtered = delete_space(line);
                std::size_t found = filtered.find_first_of("=");
                if(found == -1)
                    continue;
                std::string value="";
                std::string key = filtered.substr(0, found);
                if(found + 1 != filtered.size())
                    value = filtered.substr(found + 1, filtered.size());
                
                // value has quotes
                if(value.front() == 34 && value.back() == 34) {
                    value.erase(0);
                    value.pop_back();
                }
                std::cout<< key << " " << value << std::endl;
                // TODO : ADD KEYS
            }
        }
    };
    
    std::string env::path = ".env";
    std::map<std::string, std::unique_ptr<data>>  env::datas = {};
}

#endif
