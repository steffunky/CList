#ifndef __CLIST_H__
#define __CLIST_H__

#include "CNode.h"
#include <memory>

namespace nsSdD
{
    template <typename T>
    class CList
    {
      public :
        typedef std::shared_ptr<CNode<T>> Ptr_CNode;
        explicit CList () throw ();
        explicit CList (unsigned n) throw ();
        CList (unsigned n, const T & val) throw ();
        CList (const CList & x) throw ();
        ~CList (void) throw ();

        Ptr_CNode front () const throw ();
        Ptr_CNode back () const throw ();

        bool empty () const throw ();
        unsigned size () const throw ();

        unsigned max_size() const;

        CList& operator= (const CList & List) throw ();
        void push_front (const Ptr_CNode & Node) throw ();
        void pop_front () throw ();

        void push_back (const Ptr_CNode & Node) throw ();
        void pop_back () throw();

        void insert (unsigned Position, const Ptr_CNode & Node) throw ();
        void erase (unsigned Position, const Ptr_CNode & Node) throw ();

        void swap (CList<T> & List) throw ();
        void clear () throw ();

        void remove (const Ptr_CNode & Node) throw ();
        void unique () throw ();

        void sort () throw ();
        void reverse () throw ();

      private :
        Ptr_CNode m_Head;
        Ptr_CNode m_Tail;

    };

    #include "CList.hxx"
}

#endif // CLIST_H
