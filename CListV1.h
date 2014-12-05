#ifndef __CLISTV1_H__
#define __CLISTV1_H__

#include "CNode.h"

namespace nsSdD
{
    template <typename T>
    class CListV1
    {
      public :
        typedef std::shared_ptr<CNode<T>> Ptr_CNode;
        explicit CListV1 () noexcept;
        explicit CListV1 (unsigned n) noexcept;
        CListV1 (unsigned n, const T & val) noexcept;
        CListV1 (const CListV1 & x) noexcept;
        virtual ~CListV1 (void) noexcept;

        Ptr_CNode front () const noexcept;
        Ptr_CNode back () const noexcept;

        bool empty () const noexcept;
        unsigned size () const noexcept;

        unsigned max_size() const noexcept;

        CListV1& operator= (const CListV1 & List) noexcept;
        void push_front (const T & val) noexcept;
        void pop_front () noexcept;

        void push_back (const T & val) noexcept;
        void pop_back () throw();

        void swap (CListV1<T> & List) noexcept;
        void clear () noexcept;

        void remove (const T & val) noexcept;
        void unique () noexcept;

        void sort () noexcept;
        void reverse () noexcept;

        void resize (unsigned n, const T& val = T()) noexcept;

        void merge (CListV1 & x) noexcept;
        void assign (unsigned n, const T& val) noexcept;

        void GetSuivant() noexcept;

      private :
        Ptr_CNode m_Head;
        Ptr_CNode m_Tail;
        const static unsigned m_MaxSize = 10000;

        Ptr_CNode find (const T& val) noexcept;
        void swap (Ptr_CNode &PtrA, Ptr_CNode &PtrB) noexcept;
        void Remove (const Ptr_CNode & Node) noexcept;
    };

    #include "CListV1.hxx"
}

#endif // __CLISTV1_H__
