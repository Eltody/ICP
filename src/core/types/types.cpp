/** VUT FIT ICP 2020/2021
 * @file types.cpp
 * @brief Dátové typy použité vo výpočtoch
 * @date 3.4.2021
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */


#include "types.h"

vector2D_out::vector2D_out() : Type{"x", "y"} { }

vector2D_out::vector2D_out(double x, double y) : vector2D_out() {
	operator[]("x") = x;
	operator[]("y") = y;
}

vector3D_out::vector3D_out() : Type{"x", "y", "z"} { }

vector3D_out::vector3D_out(double x, double y, double z) : vector3D_out() {
    operator[]("x") = x;
    operator[]("y") = y;
    operator[]("z") = z;
}

matrix2x2_out::matrix2x2_out() : Type{"m11", "m12", "m21", "m22"} { }

matrix2x2_out::matrix2x2_out(double m11, double m12, double m21, double m22) : matrix2x2_out() {
	operator[]("m11") = m11;
	operator[]("m12") = m12;
	operator[]("m21") = m21;
	operator[]("m22") = m22;
}

matrix3x3_out::matrix3x3_out() : Type{"m11", "m12", "m13", "m21", "m22", "m23", "m31", "m32", "m33"} { }

matrix3x3_out::matrix3x3_out(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33) : matrix3x3_out() {
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

one_number::one_number() : Type{"Hodnota"} { }

one_number::one_number(double hodnota) : one_number() {
    operator[]("Hodnota") = hodnota;
}
