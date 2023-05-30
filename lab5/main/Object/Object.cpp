#include "Object.h"

void Object::insert(std::string key, std::string value = std::string()) {
    std::string newValue; 
    if (isEmpty(value))
        newValue = value;
    if (isValidKey(key)) 
        data[key] = newValue;
}


std::string Object::getValue(std::string name){
    return data[name]; 
}

bool Object::isValidKey(std::string key) {
    if (key.length() > 64)
        return false; 
    if (isString(key))
        return false;
    return true;
}


bool Object::isEmpty(std::string value) {
    return (value.length() == 0) ? false : true; 
}

bool Object::isString(std::string value) {
    for(int i=0; i<value.length(); i++) { 
        if(isdigit(value[i]) == true)
            return true;
    }
    return false; 
}

bool Object::findKey(std::string key) {
    return (data.find(key) == data.end()) ? false : true;
}