#pragma once
#include "Property.h"
#include <vector>

template <typename T>
class EnumProperty : public Property {
private:
    std::vector<T> mAllowedValues;

public:
    
    EnumProperty(const std::string& name, const std::vector<T>& allowedValues) 
        : Property(name), mAllowedValues(allowedValues) {}

   
    virtual int getValueCount() const override {
        return mAllowedValues.size();
    }

   
    const std::vector<T>& getAllowedValues() const {
        return mAllowedValues;
    }
};