/**
 *
 * @file    CException.h
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    23/03/2010
 *
 * @version V1.0
 *
 * @brief   Declaration de la classe CException
 *
 **/
#ifndef __CEXCEPTION_H__
#define __CEXCEPTION_H__

#include <string>
#include <iostream>
#include <exception>

#include "CstCodErr.h"
#include "CEditable.h"

namespace nsUtil
{
    class CException : public std::exception, public CEditable
    {
        std::string m_Libelle;
        unsigned    m_CodErr;

      public :
        CException (const std::string & Libelle = std::string(),
                    const unsigned      CodErr  = KNoExc)     noexcept;
        virtual ~CException (void)                            noexcept;

        const std::string & GetLibelle (void) const           noexcept;
        unsigned            GetCodErr  (void) const           noexcept;

        virtual const char* what() const                      noexcept;

      protected :
        virtual std::ostream & _Edit (std::ostream & os) const;

    }; // CException

} // namespace nsUtil

#include "CException.hxx"

#endif        /* __CEXCEPTION_H__ */
