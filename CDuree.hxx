/**
 *
 * @file    CDuree.hxx
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    07/03/2008
 *
 * @version V1.0
 *
 * @brief   Definition des methodes de la classe CDuree
 *
 **/
#ifndef __CDUREE_HXX__
#define __CDUREE_HXX__

#include "CDuree.h"

#define CDUREE nsUtil::CDuree

// Les valeurs par defaut sont rappelees en commentaires car
//   interdites

inline CDUREE::CDuree  (const ULLong_t Duree /* = UULong_t (0) */)
                                                               noexcept
    : m_Duree (Duree) { Normaliser(); }

inline CDUREE::CDuree  (const CDuree & D) noexcept
    : m_Duree (D.m_Duree), m_Secondes (D.m_Secondes),
      m_Minutes (D.m_Minutes), m_Heures (D.m_Heures),
      m_Jours (D.m_Jours) {}

inline CDUREE::~CDuree () noexcept {}

inline
ULLong_t CDUREE::GetDuree (void) const noexcept { return m_Duree; }

inline void CDUREE::SetDuree (ULLong_t D) noexcept
{
    m_Duree = D;
    Normaliser();

}  // SetDuree()

inline bool CDUREE::operator < (const CDuree & D) const noexcept
{
    return (m_Duree < D.m_Duree);

} // operator <

inline bool CDUREE::operator == (const CDuree & D) const noexcept
{
    return (m_Duree == D.m_Duree);

} // operator ==

#undef CDUREE

#endif     /* __CDUREE_HXX__ */
