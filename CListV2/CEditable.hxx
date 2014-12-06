/**
 *
 * @file    CEditable.hxx
 *
 * @authors D. Mathieu, M. Laporte
 *
 * @date    17/03/2010
 *
 * @version V2.0
 *
 **/
#ifndef __CEDITABLE_HXX__
#define __CEDITABLE_HXX__

#include <iostream>

#include "CEditable.h"

inline nsUtil::CEditable::~CEditable (void) {}

inline
std::ostream & nsUtil::operator << (std::ostream & os,
                                    const CEditable & Obj)
{
    return Obj._Edit (os);

} // operator <<

#endif      /* __CEDITABLE_HXX__ */
