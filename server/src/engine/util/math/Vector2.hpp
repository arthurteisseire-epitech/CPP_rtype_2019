/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Created by Arthamios
*/

#ifndef RTYPE_VECTOR2_HPP
#define RTYPE_VECTOR2_HPP

namespace mut
{
    template <typename T>
    struct Vector2 {
        Vector2(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}

        Vector2 operator+(const Vector2 &v1) const;
        Vector2 operator-(const Vector2 &v1) const;
        Vector2 operator+=(const Vector2 &v1);
        Vector2 operator-=(const Vector2 &v1);
        bool operator==(const Vector2 &v1) const;
        bool operator!=(const Vector2 &v1) const;

        T x;
        T y;
    };

    template<typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2<T> &v1) const
    {
        return Vector2<T>(this->x + v1.x, this->y + v1.y);
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2<T> &v1) const
    {
        return Vector2<T>(this->x - v1.x, this->y - v1.y);
    }

    template<typename T>
    bool Vector2<T>::operator==(const Vector2<T> &v1) const
    {
        return this->x == v1.x && this->y == v1.y;
    }

    template<typename T>
    bool Vector2<T>::operator!=(const Vector2 &v1) const
    {
        return this->x != v1.x || this->y != v1.y;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator+=(const Vector2 &v1)
    {
        *this = *this + v1;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-=(const Vector2 &v1)
    {
        *this = *this - v1;
        return *this;
    }

    using Vec2f = Vector2<float>;
    using Vec2i = Vector2<int>;
    using Vec2u = Vector2<unsigned>;
    using Vec2d = Vector2<double>;
}

#endif
