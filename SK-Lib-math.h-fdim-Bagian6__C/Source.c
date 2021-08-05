#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main(void) {
    printf("fdim(4, 1) = %f, fdim(1, 4)=%f\n", fdim(4, 1), fdim(1, 4));
    printf("fdim(4,-1) = %f, fdim(1,-4)=%f\n", fdim(4, -1), fdim(1, -4));
    
    //penanganan error / kesalahan
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("fdim(1e308, -1e308) = %f\n", fdim(1e308, -1e308));

    if (errno == ERANGE) {
        perror("    errno == ERANGE");
    }

    if (fetestexcept(FE_OVERFLOW)) {
        puts("    FE_OVERFLOW raised");
    }

    _getch();
    return 0;
}