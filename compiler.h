#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <list>
#include <map>

typedef enum { typeCon , typeId, typeOpr } nodeEnum;

enum class ValType {
    UNKNOWN,
    INT,
    FLOAT,
    DOUBLE,
    BOOL,
    STRING
};

struct Value {
    union {
        int intValue;
        float floatValue;
        double doubleValue;
        bool boolValue;
        char *stringValue;
    };
    ValType type;

    Value() { type = ValType::UNKNOWN; }
    Value(int value) : intValue(value) { type = ValType::INT; }
    Value(float value) : floatValue(value) { type = ValType::FLOAT; }
    Value(double value) : doubleValue(value) { type = ValType::DOUBLE; }
    Value(bool value) : boolValue(value) { type = ValType::BOOL; }
    Value(char *value) : stringValue(value) { type = ValType::STRING; }
    Value(int value, ValType type) : intValue(value), type(type) {}
    Value(float value, ValType type) : floatValue(value), type(type) {}
    Value(double value, ValType type) : doubleValue(value), type(type) {}
};

struct conNodeType {
    union {
        int intValue;
        float floatValue;
        double doubleValue;
        char *stringValue;
    };
    ValType type;
};

struct idNodeType {
    std::string *name;
};

struct oprNodeType {
    int oper;
    int nops;
    struct nodeTypeTag *op[2];
};

typedef struct nodeTypeTag {
    nodeEnum type;

    union {
        conNodeType con;
        idNodeType id;
        oprNodeType opr;
    };
} nodeType;

struct SymbolTable {
    std::string name;
    ValType type;
    int intValue;
    float floatValue;
    double doubleValue;
};



extern std::map<std::string,SymbolTable> symbolTable;

#endif // COMPILER_H