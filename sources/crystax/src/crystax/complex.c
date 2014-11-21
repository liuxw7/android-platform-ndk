/*
 * Copyright (c) 2011-2014 CrystaX .NET.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY CrystaX .NET ''AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL CrystaX .NET OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of CrystaX .NET.
 */

#include <complex.h>
#include <float.h>
#include <math.h>

#define BF(name)  long double complex name ## l (long double complex x) { return name((double complex)x); }

BF(cacos);
BF(cacosh);
BF(casin);
BF(casinh);
BF(catan);
BF(catanh);
BF(ccos);
BF(ccosh);
BF(cexp);
BF(csin);
BF(csinh);
BF(csqrt);
BF(ctan);
BF(ctanh);

double cabs(double complex x)
{
    return hypot(creal(x), cimag(x));
}

float cabsf(float complex x)
{
    return hypotf(crealf(x), cimagf(x));
}

long double cabsl(long double complex x)
{
    return cabs((double complex)x);
}

double carg(double complex x)
{
    return atan(cimag(x) / creal(x));
}

float cargf(float complex x)
{
    return atanf(cimagf(x) / crealf(x));
}

long double cargl(long double complex x)
{
    return carg((double complex)x);
}

double complex clog(double complex x)
{
    return log(cabs(x)) + I * carg(x);
}

float complex clogf(float complex x)
{
    return logf(cabsf(x)) + I * cargf(x);
}

long double complex clogl(long double complex x)
{
    return clog((double complex)x);
}

double complex cpow(double complex x, double complex y)
{
    return cexp(y * clog(x));
}

float complex cpowf(float complex x, float complex y)
{
    return cexpf(y * clogf(x));
}

long double complex cpowl(long double complex x, long double complex y)
{
    return cpow((double complex)x, (double complex)y);
}