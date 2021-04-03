/** ICP Project 2017/2018: BlockEditor
 * @file types.cpp
 * @brief Custom data types used in schemes
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "types.h"

scal::scal() : Type{"val"} { }

scal::scal(double val) : scal()
{
	operator[]("val") = val;
}

vec2::vec2() : Type{"x", "y"} { }

vec2::vec2(double x, double y) : vec2()
{
	operator[]("x") = x;
	operator[]("y") = y;
}

vec3::vec3() : Type{"x", "y", "z"} { }

vec3::vec3(double x, double y, double z) : vec3()
{
    operator[]("x") = x;
    operator[]("y") = y;
    operator[]("z") = z;
}

mat2::mat2() : Type{"m11", "m12", "m21", "m22"} { }

mat2::mat2(double m11, double m12, double m21, double m22) : mat2()
{
	operator[]("m11") = m11;
	operator[]("m12") = m12;
	operator[]("m21") = m21;
	operator[]("m22") = m22;
}

mat3::mat3() : Type{"m11", "m12", "m13", "m21", "m22", "m23", "m31", "m32", "m33"} { }

mat3::mat3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33) : mat3()
{
    operator[]("m11") = m11;
    operator[]("m12") = m12;
    operator[]("m13") = m13;
    operator[]("m21") = m21;
    operator[]("m22") = m22;
    operator[]("m23") = m23;
    operator[]("m31") = m31;
    operator[]("m32") = m32;
    operator[]("m33") = m33;
}

