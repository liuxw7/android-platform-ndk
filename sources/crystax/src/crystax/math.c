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

#include <math.h>
#include <stdlib.h>
#include <fenv.h>

#if __SOFTFP__

int __softfloat_float_rounding_mode = 0;
int __softfloat_float_exception_mask = 0;
int __softfloat_float_exception_flags = 0;
const fenv_t __crystax_softfloat_fe_dfl_env = 0;

void __softfloat_float_raise(int e)
{
    (void)e;
    abort();
}

#endif /* __SOFTFP__ */

#define BF(name)  long double name ## l (long double x) { return name((double)x); }
#define BF2(name) long double name ## l (long double x, long double y) { return name((double)x, (double)y); }

BF(cosh);
BF(erf);
BF(erfc);
BF(lgamma);
BF(sinh);
BF(tanh);
BF(tgamma);
BF2(pow);

void sincos(double x, double *s, double *c)
{
    return __builtin_sincos(x, s, c);
}

void sincosf(float x, float *s, float *c)
{
    return __builtin_sincosf(x, s, c);
}

void sincosl(long double x, long double *s, long double *c)
{
    return __builtin_sincosl(x, s, c);
}