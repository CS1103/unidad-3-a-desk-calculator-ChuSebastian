#ifndef PROYECTO_3_DESCENT_H
#define PROYECTO_3_DESCENT_H

#include "Headers.h"
#include "ErrorHandling.h"
#include "Input.h"

extern map<string,double> table;

double expr(bool);
double term(bool);


double prim(bool get){
    if (get) ts.get();
    switch (ts.current().kind) {
        case Kind::number:
        { double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name:
        { double& v = table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) v = expr(true);
            return v;
        }
        case Kind::minus:
            return -prim(true);
        case Kind::lp:
        { auto e = expr(true);
            if (ts.current().kind != Kind::rp) return error("')' expected");
            ts.get();
            return e;
        }
        default:
            return error("primar y expected");
    }
}



double expr(bool get){
    double left = term(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}


double term(bool get)
{
    double left = prim(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::div:
                if (auto d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}




#endif //PROYECTO_3_DESCENT_H
