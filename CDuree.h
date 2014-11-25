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

        void Normaliser (void)                                 throw ();

        virtual std::ostream & _Edit (std::ostream & os) const;

      public :
        explicit CDuree  (const ULLong_t Duree = ULLong_t (0)) throw ();
        CDuree  (const CDuree & D)                             throw ();
        virtual ~CDuree ()                                     throw ();

        ULLong_t GetDuree (void) const                         throw ();
        void SetDuree (const ULLong_t Duree = ULLong_t (0))    throw ();

        CDuree & operator ++ (void)                            throw ();
        CDuree   operator ++ (int)                             throw ();
        CDuree & operator -- (void)                  throw (CException);
        CDuree   operator -- (int)                   throw (CException);

        CDuree operator + (ULLong_t Duree) const               throw ();
        CDuree operator - (ULLong_t Duree) const     throw (CException);

        CDuree & operator += (ULLong_t D)                      throw ();
        CDuree & operator -= (ULLong_t D)            throw (CException);

        CDuree operator + (const CDuree & D) const             throw ();
        CDuree operator - (const CDuree & D) const   throw (CException);

        CDuree & operator += (const CDuree & D)                throw ();
        CDuree & operator -= (const CDuree & D)      throw (CException);

        // Operateurs de comparaison et d'identite

        bool operator <  (const CDuree & D) const              throw ();
        bool operator == (const CDuree & D) const              throw ();

    }; // CDuree

} // namespace nsUtil

#include "CDuree.hxx"

#endif  /* __CDUREE_H__ */
