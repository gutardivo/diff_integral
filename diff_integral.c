#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <mpfr.h>
#include <mpc.h>

int main() {
    mpfr_t x, result_diff, result_int;
    
    mpfr_init2(x, 128);
    mpfr_init2(result_diff, 128);
    mpfr_init2(result_int, 128);

    mpfr_set_d(x, 1.0, MPFR_RNDN);

    // Diff
    mpfr_mul_ui(x, x, 15, MPFR_RNDN);
    mpfr_tan(result_diff, x, MPFR_RNDN);
    mpfr_sub(result_diff, x, result_diff, MPFR_RNDN);

    // Int
    mpfr_set_d(x, 1.0, MPFR_RNDN);
    mpfr_mul_ui(x, x, 15, MPFR_RNDN);
    mpfr_div_ui(x, x, 5, MPFR_RNDN);
    mpfr_set(result_int, x, MPFR_RNDN);

    gmp_printf("Differentiation result: %.20Rf\n", result_diff);
    gmp_printf("Integration result: %.20Rf\n", result_int);

    mpfr_clear(x);
    mpfr_clear(result_diff);
    mpfr_clear(result_int);

    return 0;
}
