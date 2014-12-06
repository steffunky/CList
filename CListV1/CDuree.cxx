/**
 *
 * @file    CDuree.cxx
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    21/04/2010
 *
 * @version V1.0
 *
 * @brief   Definition des methodes de la classe CDuree
 *
 **/
#include <iostream>
#include <iomanip>

#include "CDuree.h"
#include "CstCodErr.h"
#include "CException.h"

#define CDUREE nsUtil::CDuree

using namespace std;
using namespace nsUtil;

// Les valeurs par defaut sont rappelees en commentaires car
//   interdites

void CDUREE::Normaliser (void) throw ()
{
      m_Secondes = m_Duree % 60;
      m_Minutes  = m_Duree / 60 % 60;
      m_Heures   = m_Duree / 3600 % 24;
      m_Jours    = m_Duree / 86400;

} // Normaliser()

ostream & CDUREE::_Edit (ostream & os) const
{
    return
         os << '['                           << setfill (' ')
            << setw (6) << m_Jours    << ':' << setfill ('0')
            << setw (2) << m_Heures   << ':'
            << setw (2) << m_Minutes  << ':'
            << setw (2) << m_Secondes << ']' << setfill (' ');

} // _Edit()

CDuree CDUREE::operator - (ULLong_t D) const throw (CException)
{
    if (m_Duree < D)
        throw CException ("-- : operation interdite",
                          KExcOpInterdite);

    return CDuree (m_Duree - D);

} // operator -

CDuree CDUREE::operator + (ULLong_t D) const throw ()
{
    return CDuree (m_Duree + D);

} // operator +

CDuree CDUREE::operator - (const CDuree & D) const throw (CException)
{
    if (m_Duree < D.m_Duree)
        throw CException ("-- : operation interdite",
                          KExcOpInterdite);

    return CDuree (m_Duree - D.m_Duree);

} // operator -

CDuree CDUREE::operator + (const CDuree & D) const throw ()
{
    return CDuree (m_Duree + D.m_Duree);

} // operator +

CDuree & CDUREE::operator ++ (void) throw ()
{
    ++m_Duree;
    Normaliser();
    return *this;

} // operator ++  pre

CDuree CDUREE::operator ++ (int) throw ()
{
    return CDuree (m_Duree++);

} // operator ++ post

CDuree & CDUREE::operator -- (void) throw (CException)
{
    if (m_Duree == 0)
        throw CException ("-- : operation interdite",
                          KExcOpInterdite);
    --m_Duree;
    Normaliser();
    return *this;

} // operator -- pre

CDuree CDUREE::operator -- (int) throw (CException)
{
    if (m_Duree == 0)
        throw CException ("-- : operation interdite",
                          KExcOpInterdite);

    return CDuree (m_Duree--);

} // operator -- post

CDuree & CDUREE::operator += (ULLong_t D) throw ()
{
    m_Duree += D;
    Normaliser();

    return *this;

} // operator +=

CDuree & CDUREE::operator -= (ULLong_t D) throw (CException)
{
    if (m_Duree < D)
        throw CException ("-- : operation interdite",
                          KExcOpInterdite);
    m_Duree -= D;
    Normaliser();

    return *this;

} // operator -=

CDuree & CDUREE::operator += (const CDuree & D) throw ()
{
    m_Duree += D.m_Duree;
    Normaliser();

    return *this;

} // operator +=

CDuree & CDUREE::operator -= (const CDuree & D) throw (CException)
{
    if (m_Duree < D.m_Duree)
        throw CException ("-- : operation interdite",
                          KExcOpInterdite);
    m_Duree -= D.m_Duree;
    Normaliser();

    return *this;

} // operator -=

#undef CDUREE

