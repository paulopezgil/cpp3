#ifndef DATA_HH
#define DATA_HH

#include <string>
#include <vector>
#include <memory>

class Data
{
    using DataVector = std::vector<std::shared_ptr<std::string>>;
    
    DataVector d_data;
    
    public:
        using value_type = std::string;     // for back_inserter
        void push_back(std::string const &str);
};

inline void Data::push_back(std::string const &str)
{
    d_data.push_back(std::make_shared<std::string>(str));
}

#endif