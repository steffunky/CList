/*
 * CNode.h
 *
 *  Created on: 24 nov. 2014
 *      Author: micka
 */

#ifndef __CNODE_H__
#define __CNODE_H__

#include <memory>

namespace nsSdD
{
    template <typename T>

    class CNode : public T
    {
      public :
        typedef std::shared_ptr<CNode<T>> Ptr_CNode;
        CNode (const T         & Data     = T(),
               const Ptr_CNode & Suivant = nullptr,
               const Ptr_CNode & Precedent = nullptr) noexcept;

        ~CNode () noexcept;

        T GetData () const noexcept;
        Ptr_CNode GetSuivant () const noexcept;
        Ptr_CNode GetPrecedent () const noexcept;

        void SetData (const T & Data) noexcept;
        void SetSuivant (const Ptr_CNode & Suivant) noexcept;
        void SetPrecedent (const Ptr_CNode & Precedent) noexcept;

      private :
        T m_Data;
        Ptr_CNode m_Suivant;
        Ptr_CNode m_Precedent;

    };

    #include "CNode.hxx"
    #undef Ptr_CNode
}

#endif /* CNODE_H_ */
