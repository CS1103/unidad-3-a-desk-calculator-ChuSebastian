#ifndef PROYECTO_3_PARSER_H
#define PROYECTO_3_PARSER_H
#include "Input.h"
#include "ErrorHandling.h"
#include "Headers.h"

enum class Kind: char{
    name, number, end,
    plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=', lp = '(', rp =')'
};

struct Token{
    Kind kind;
    string string_value;
    double number_value;
};






#endif //PROYECTO_3_PARSER_H
