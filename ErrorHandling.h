#ifndef PROYECTO_3_ERRORHANDLING_H
#define PROYECTO_3_ERRORHANDLING_H
#include "Headers.h"

int no_of_errors;

double error(const string& s){
    no_of_errors++;
    cerr << "error: " << s << endl << endl;
    return 1;
}


#endif //PROYECTO_3_ERRORHANDLING_H
