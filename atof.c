/* My implementation of atof with an optional exponent */
#include <stdio.h>
#include <ctype.h>

double atof(char s[]) {

    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = s[i] == '-' ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        int exp;
        double exp_sign = s[++i] == '-' ? 0.1: 10.0;
        if (s[i] == '-' || s[i] == '+') i++;
        for (exp=0; isdigit(s[i]); i++)
            exp = exp * 10 + s[i] - '0';
        for (; exp > 0; exp--)
            val *= exp_sign;
    }
    return sign * val / power;
}

int main (void) {

    printf("%.15lf : %lf : %lf\n", atof("123.45e-6"), atof("1.0e10"), atof("-0.123"));

    return 0;
}
