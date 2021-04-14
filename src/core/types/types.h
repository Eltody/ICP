#include "../type.h"

/**
 * @brief Dátový typ pre 2D vektor
 */
class vector2D_out : public Type {
public:
    vector2D_out();
    vector2D_out(double x, double y);
};

/**
 * @brief Dátový typ pre 3D vektor
 */
class vector3D_out : public Type {
public:
    vector3D_out();
    vector3D_out(double x, double y , double z);
};

/**
 * @brief Dátový typ pre 2x2 maticu
 */
class matrix2x2_out : public Type {
public:
    matrix2x2_out();
    matrix2x2_out(double m11, double m12, double m21, double m22);
};

/**
 * @brief Dátový typ pre 3x3 maticu
 */
class matrix3x3_out : public Type {
public:
    matrix3x3_out();
    matrix3x3_out(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);
};


/**
 * @brief Dátový typ pre jednoprvkový výsledok matematického výrazu
 */
class one_number : public Type {
public:
    one_number();
    one_number(double hodnota);
};
