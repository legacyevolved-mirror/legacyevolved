#pragma once
#include <string>


class Property {
protected:
    std::string mName; 

public:
    Property(const std::string& name) : mName(name) {}
    virtual ~Property() = default;

    
    const std::string& getName() const { return mName; }
    
   
    virtual int getValueCount() const = 0;
};