// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Color
// -----------------------------------------------------------------------------
//durchaus erweitert... durch Multiplikationen

#ifndef BUW_COLOR_HPP
#define BUW_COLOR_HPP

#include <iostream>

struct Color
{
  //KONSTRUTOREN----------------------------------------------------------------
  Color() : r(0), g(0), b(0) {}
  Color(float red, float green, float blue) : r(red), g(green), b(blue) {}

  //VARIABLEN-------------------------------------------------------------------
  float r;
  float g;
  float b;

  //FUNKTIONEN:OPERATIONEN-------------------------------------------------------
  Color& operator+=(Color const& other)
  {
    r += other.r;
    g += other.g;
    b += other.b;
    return *this;
  }
  Color& operator-=(Color const& other)
  {
    r -= other.r;
    g -= other.g;
    b -= other.b;
    return *this;
  }
  Color& operator*=(Color const& other)
  {
      r *= other.r;
      g *= other.g;
      b *= other.b;
      return *this;
  }
  Color& operator*=(float other) //Fürs Skalarprodukt in givacolor!
  {
      r *= other;
      g *= other;
      b *= other;
      return *this;
  }

  //FRIENDS--------------------------------------------------------------------
    //OPERATION----------------------------------------------------------------
    friend Color operator+(Color const& a, Color const& b)
    {
      auto tmp(a);
      tmp += b;
      return tmp;
    }
    friend Color operator-(Color const& a, Color const& b)
    {
      auto tmp(a);
      tmp -= b;
      return tmp;
    } 
    friend Color operator*(Color const& a, float b)  //Fürs Skalarprodukt in givacolor!
    {
      auto tmp(a);
      tmp *= b;
      return tmp;
    }
    friend Color operator*(Color const& a, Color const& b) //Für Multiplikation in givacolor!
    {
      return Color(a)*=b;
    }

    //WEITERE-----------------------------------------------------------------
    friend std::ostream& operator<<(std::ostream& os, Color const& c)
    {
      os << "(" << c.r << "," << c.g << "," << c.b << ")";
      return os;
    }
    friend bool operator==(Color const& lhs, Color const& rhs)
    {
      return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
    }
};

#endif //#define BUW_COLOR_HPP
