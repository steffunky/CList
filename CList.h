#ifndef __CLIST_H__
#define __CLIST_H__

#include "CNode.h"

namespace nsSdD
{
    template <typename T>
    #define Ptr_CNode shared_ptr<CNode<T>>

    class CList : public T
    {
      private :
        Ptr_CNode m_Head;
        Ptr_CNode m_Tail;


      public :
        explicit CList () throw ();
        explicit CList (size_type n) throw ();
        CList (size_type n, const value_type & val) throw ();
        CList (const CList & x) throw ();
        ~CList (void) throw ();

        Ptr_CNode front () const throw ();
        Ptr_CNode back () const throw ();

        bool Empty () const throw ();
        size_type size () const throw ();

        CList& operator= (const CList & List) throw ();
        void push_front (const Ptr_CNode & Node) throw ();
        void pop_front () throw ();

        void push_back (const Ptr_CNode & Node) throw ();
        void pop_back () throw();

        void insert (unsigned Position, const Ptr_CNode & Node) throw ();
        void erase (unsigned Position, const Ptr_CNode & Node) throw ();

        void swap (const CList & List) throw ();
        void clear () throw ();

        void remove (const Ptr_CNode & Node) throw ();
        void unique () throw ();

        void sort () throw ();
        void reverse () throw ();
    };

    #include "CList.hxx"
}

#endif // CLIST_H
