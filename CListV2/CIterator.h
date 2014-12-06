#ifndef __CITERATOR_H__
#define __CITERATOR_H__

#include "CNode.h"

namespace nsSdD
{
    template <typename T>
    class CIterator
    {
        typedef std::shared_ptr<nsSdD::CNode<T>> Ptr_CNode;
        private :
            Ptr_CNode m_CurrentNode;
        public :
            CIterator (const Ptr_CNode &CurrentNode = nullptr) noexcept;
            CIterator operator++ () noexcept;
            CIterator operator++(int) noexcept;
            CIterator operator-- () noexcept;
            CIterator operator-- (int) noexcept;
            Ptr_CNode GetCurrentNode() const noexcept;
            Ptr_CNode operator->() noexcept;
            Ptr_CNode& operator* () noexcept;
            bool operator==(const CIterator<T> &It) noexcept;
            CIterator<T> operator= (const CIterator<T> &It) noexcept;
    };
    #include "CIterator.hxx"
}

#endif // __CITERATOR_H__
