/**
 *
 * @file    CException.hxx
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    23/03/2010
 *
 * @version V1.0
 *
 * @brief   classe CException
 *
 **/
#if ! defined __CEXCEPTION_HXX__
#define       __CEXCEPTION_HXX__

#include <string>

#include "CException.h"

#define CEXC nsUtil::CException

inline
CEXC::CException (const std::string & Libelle /* = std::string () */,
                  const unsigned      CodErr  /* = KNoExc         */)
                                                               noexcept
    : m_Libelle (Libelle), m_CodErr (CodErr) {}

inline const std::string & CEXC::GetLibelle (void) const noexcept
{
    return m_Libelle;

} // GetLibelle()

inline
unsigned CEXC::GetCodErr (void) const noexcept { return m_CodErr;  }

inline CEXC::~CException (void) noexcept {}

inline
const char* CEXC::what() const throw()  { return m_Libelle.c_str(); }

#undef CEXC

#endif     /* __CEXCEPTION_HXX__ */
