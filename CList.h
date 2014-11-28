#ifndef __CLIST_H__
#define __CLIST_H__

#include "CNode.h"

namespace nsSdD
{
    template <typename T>
    class CList
    {
      public :
        typedef std::shared_ptr<CNode<T>> Ptr_CNode;
        explicit CList () noexcept;
        explicit CList (unsigned n) noexcept;
        CList (unsigned n, const T & val) noexcept;
        CList (const CList & x) noexcept;
        ~CList (void) noexcept;

        Ptr_CNode front () const noexcept;
        Ptr_CNode back () const noexcept;

        bool empty () const noexcept;
        unsigned size () const noexcept;

        unsigned max_size() const;

        CList& operator= (const CList & List) noexcept;
        void push_front (const T & val) noexcept;
        void pop_front () noexcept;

        void push_back (const T & val) noexcept;
        void pop_back () throw();

        void swap (CList<T> & List) noexcept;
        void clear () noexcept;

        void remove (const T & Node) noexcept;
        void unique () noexcept;

        void sort () noexcept;
        void reverse () noexcept;

        void resize (unsigned n, const T& val = T()) noexcept;

        void merge (CList & x) noexcept;
        void assign (unsigned n, const T& val) noexcept;

      private :
        Ptr_CNode m_Head;
        Ptr_CNode m_Tail;

        Ptr_CNode find (const T& val) noexcept;

    };

    #include "CList.hxx"
}

#endif // CLIST_H
