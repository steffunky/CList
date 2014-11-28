/**
 *
 * @file    CDuree.h
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    17/03/2010
 *
 * @version V1.0
 *
 * @brief   Declaration de la classe CDuree
 *
 **/
#ifndef __CDUREE_H__
#define __CDUREE_H__

typedef unsigned long long ULLong_t;

#include "CEditable.h"
#include "CException.h"

namespace nsUtil
{
    class CDuree : public CEditable
    {
      private :
        ULLong_t       m_Duree;
        short unsigned m_Secondes;
        short unsigned m_Minutes;
        short unsigned m_Heures;
        ULLong_t       m_Jours;

        void Normaliser (void)                                 noexcept;

        virtual std::ostream & _Edit (std::ostream & os) const;

      public :
        explicit CDuree  (const ULLong_t Duree = ULLong_t (0)) noexcept;
        CDuree  (const CDuree & D)                             noexcept;
        virtual ~CDuree ()                                     noexcept;

        ULLong_t GetDuree (void) const                         noexcept;
        void SetDuree (const ULLong_t Duree = ULLong_t (0))    noexcept;

        CDuree & operator ++ (void)                            noexcept;
        CDuree   operator ++ (int)                             noexcept;
        CDuree & operator -- (void)                  throw (CException);
        CDuree   operator -- (int)                   throw (CException);

        CDuree operator + (ULLong_t Duree) const               noexcept;
        CDuree operator - (ULLong_t Duree) const     throw (CException);

        CDuree & operator += (ULLong_t D)                      noexcept;
        CDuree & operator -= (ULLong_t D)            throw (CException);

        CDuree operator + (const CDuree & D) const             noexcept;
        CDuree operator - (const CDuree & D) const   throw (CException);

        CDuree & operator += (const CDuree & D)                noexcept;
        CDuree & operator -= (const CDuree & D)      throw (CException);

        // Operateurs de comparaison et d'identite

        bool operator <  (const CDuree & D) const              noexcept;
        bool operator == (const CDuree & D) const              noexcept;

    }; // CDuree

} // namespace nsUtil

#include "CDuree.hxx"

#endif  /* __CDUREE_H__ */
