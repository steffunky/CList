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
        Ptr_CNode m_NextNode;
        Ptr_CNode m_PrecNode;

      public :
        CNode (const T         & Data     = T(),
               const Ptr_CNode & NextNode = nullptr,
               const Ptr_CNode & PrecNode = nullptr) throw ();

        ~CNode () throw ();

        T GetData () const throw ();
        Ptr_CNode GetNextNode () const throw ();
        Ptr_CNode GetPrecNode () const throw ();

        void SetData (const T & Data) throw ();
        void SetNextNode (const Ptr_CNode & NextNode) throw ();
        void SetPrecNode (const Ptr_CNode & PrecNode) throw ();
    };

    #include "CNode.hxx"

}

#endif /* CNODE_H_ */
