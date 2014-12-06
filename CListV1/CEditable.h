/**
 *
 * @file    CEditable.h
 *
 * @authors D. Mathieu, M. Laporte
 *
 * @date    16/03/2009
 *
 * @version V2.0
 *
 * @brief   declaration de la classe CEditable dans nsUtil
 *
 **/
#ifndef __CEDITABLE_H__
#define __CEDITABLE_H__

#include <iostream>

namespace nsUtil
{
    class CEditable;
    std::ostream & operator << (std::ostream & os,
                                const CEditable & Obj);
    class CEditable
    {
      protected :
        virtual std::ostream & _Edit (std::ostream & os) const = 0;

      public :
        virtual ~CEditable (void);
        friend std::ostream & operator << (std::ostream & os,
                                           const CEditable & Obj);
    }; // CEditable

} // nsUtil

#include "CEditable.hxx"

#endif     /* __CEDITABLE_H__ */
