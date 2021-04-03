/** ICP Project 2017/2018: BlockEditor
 * @file types.h
 * @brief Custom data types for schemes header
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef TYPES_H
#define TYPES_H

#include "../type.h"

/**
 * @brief Scalar value
 */
class scal : public Type {
public:
	scal();
	scal(double val);
};

/**
 * @brief 2D vector
 */
class vec2 : public Type {
public:
	vec2();
	vec2(double x, double y);
};

/**
 * @brief 3D vector
 */
class vec3 : public Type {
public:
    vec3();
    vec3(double x, double y , double z);
};

/**
 * @brief 2x2 matrix
 */
class mat2 : public Type {
public:
	mat2();
	mat2(double m11, double m12, double m21, double m22);
};

/**
 * @brief 3x3 matrix
 */
class mat3 : public Type {
public:
    mat3();
    mat3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);
};


//********************************************//


/**
 * @brief Scalar value
 */
class math : public Type {
public:
    math();
    math(double val);
};




#endif // TYPES_H
