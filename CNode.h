/*
 * CNode.h
 *
 *  Created on: 24 nov. 2014
 *      Author: micka
 */

#ifndef __CNODE_H__
#define __CNODE_H__

namespace nsSdD
{
    template <class T>;
    #define Ptr_CNode shared_ptr<CNode<T>>
    class CNode : public T
    {
      private :
        T m_Data;
        Ptr_CNode m_Suivant;
        Ptr_CNode m_Precedent;

      public :
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
    };

    #include "CNode.hxx"
    #undef Ptr_CNode
}

#endif /* CNODE_H_ */
