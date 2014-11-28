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
               const Ptr_CNode & Precedent = nullptr) throw ();

        ~CNode () throw ();

        T GetData () const throw ();
        Ptr_CNode GetSuivant () const throw ();
        Ptr_CNode GetPrecedent () const throw ();

        void SetData (const T & Data) throw ();
        void SetSuivant (const Ptr_CNode & Suivant) throw ();
        void SetPrecedent (const Ptr_CNode & Precedent) throw ();

      private :
        T m_Data;
        Ptr_CNode m_Suivant;
        Ptr_CNode m_Precedent;

    };

    #include "CNode.hxx"
    #undef Ptr_CNode
}

#endif /* CNODE_H_ */
