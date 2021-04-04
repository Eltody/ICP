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
 * @brief Dátový typ pre 2D vektor
 */
class vec2 : public Type {
public:
	vec2();
	vec2(double x, double y);
};

/**
 * @brief Dátový typ pre 3D vektor
 */
class vec3 : public Type {
public:
    vec3();
    vec3(double x, double y , double z);
};

/**
 * @brief Dátový typ pre 2x2 maticu
 */
class mat2 : public Type {
public:
	mat2();
	mat2(double m11, double m12, double m21, double m22);
};

/**
 * @brief Dátový typ pre 3x3 maticu
 */
class mat3 : public Type {
public:
    mat3();
    mat3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);
};


/**
 * @brief Dátový typ pre jednoprvkový výsledok matematického výrazu
 */
class math : public Type {
public:
    math();
    math(double hodnota);
};



#endif // TYPES_H
