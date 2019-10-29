#ifndef PROYECTO_3_CALCULATE_H
#define PROYECTO_3_CALCULATE_H
#include "Input.h"
#include "Descent.h"

void calculate(){
    for (;;){
        ts.get();
        if (ts.current().kind == Kind::end) break;
        if (ts.current().kind == Kind::print) continue;
        cout << expr(false) << "\n";
    }
}

#endif //PROYECTO_3_CALCULATE_H
