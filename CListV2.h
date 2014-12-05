#ifndef __CLISTV2_H__
#define __CLISTV2_H__

#include "CNode.h"
#include "CIterator.h"

namespace nsSdD
{
    template <typename T>
    class CListV2
    {
      public :
        typedef std::shared_ptr<CNode<T>> Ptr_CNode;
        typedef CIterator<T> iterator;
        typedef CCIterator<T> iterator;
        typedef CRIterator<T> reverse_iterator;
        explicit CListV2 () noexcept;
        explicit CListV2 (unsigned n) noexcept;
        CListV2 (unsigned n, const T & val) noexcept;
        CListV2 (const CListV2 & x) noexcept;
        virtual ~CListV2 (void) noexcept;

        Ptr_CNode front () const noexcept;
        Ptr_CNode back () const noexcept;

        bool empty () const noexcept;
        unsigned size () const noexcept;

        unsigned max_size() const;

        CListV2& operator= (const CListV2 & List) noexcept;
        void push_front (const T & val) noexcept;
        void pop_front () noexcept;

        void push_back (const T & val) noexcept;
        void pop_back () throw();

        void swap (CListV2<T> & List) noexcept;
        void clear () noexcept;

        void remove (const T & val) noexcept;
        void unique () noexcept;

        void sort () noexcept;
        void reverse () noexcept;

        void resize (unsigned n, const T& val = T()) noexcept;

        void merge (CListV2 & x) noexcept;
        void assign (unsigned n, const T& val) noexcept;
        void assign (iterator first, iterator last) noexcept;

        void insert (iterator position, size_type n, const value_type& val);
        iterator insert (iterator position, const value_type& val);
        iterator erase (const_iterator position);
        iterator erase (const_iterator first, const_iterator last);
        void splice (const_iterator position, list& x);
        void splice (const_iterator position, list& x, const_iterator i);


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
