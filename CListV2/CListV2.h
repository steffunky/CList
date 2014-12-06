#ifndef __CLISTV2_H__
#define __CLISTV2_H__

#include "CNode.h"
#include "CIterator.h"
#include "CRIterator.h"

namespace nsSdD
{
    template <typename T>
    class CList
    {
      public :
        typedef std::shared_ptr<CNode<T>> Ptr_CNode;
        typedef CIterator<T> iterator;
        typedef CIterator<const T> const_iterator;
        typedef CRIterator<T> reverse_iterator;
        typedef CRIterator<const T> const_reverse_iterator;

        explicit CList () noexcept;
        explicit CList (unsigned n) noexcept;
        CList (unsigned n, const T & val) noexcept;
        CList (const CList & x) noexcept;
        virtual ~CList (void) noexcept;

        Ptr_CNode front () const noexcept;
        Ptr_CNode back () const noexcept;

        bool empty () const noexcept;
        unsigned size () const noexcept;

        unsigned max_size() const;

        CList& operator= (const CList<T> & List) noexcept;
        void push_front (const T & val) noexcept;
        void pop_front () noexcept;

        void push_back (const T & val) noexcept;
        void pop_back () throw();

        void swap (CList<T> & List) noexcept;
        void clear () noexcept;

        void remove (const T & val) noexcept;
        void unique () noexcept;

        void sort () noexcept;
        void reverse () noexcept;

        void resize (unsigned n, const T& val = T()) noexcept;

        void merge (CList & x) noexcept;
        void assign (unsigned n, const T& val) noexcept;
        void assign (iterator first, iterator last) noexcept;

        void insert (iterator position, unsigned n, const T& val);
        iterator insert (iterator position, const T& val);
        iterator erase (const_iterator position);
        iterator erase (const_iterator first, const_iterator last);
        void splice (const_iterator position, CList<T>& x);
        void splice (const_iterator position, CList<T>& x, const_iterator i);


        unsigned max_size() noexcept;

        iterator begin() noexcept;
        iterator end() noexcept;
        reverse_iterator rbegin() noexcept;
        reverse_iterator rend() noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend () const noexcept;

      private :
        Ptr_CNode m_Head;
        Ptr_CNode m_Tail;
        const static unsigned m_MaxSize = 10000;

        Ptr_CNode find (const T& val) noexcept;
        void swap (Ptr_CNode &PtrA, Ptr_CNode &PtrB) noexcept;
        void Remove (const Ptr_CNode & Node) noexcept;
    };

    //#include "CListV2.hxx"
}

#endif // CLIST_H
