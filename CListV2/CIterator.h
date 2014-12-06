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
            CIterator<T> (const Ptr_CNode &CurrentNode = nullptr) noexcept;
            CIterator<T> operator++ () noexcept;
            CIterator<T> operator++(int) noexcept;
            CIterator<T> operator-- () noexcept;
            CIterator<T> operator-- (int) noexcept;
            CIterator<T> operator* () noexcept;
            Ptr_CNode GetCurrentNode() const noexcept;
            std::shared_ptr<CIterator<T>> operator->() noexcept;
            bool operator==(const CIterator<T> &It) noexcept;
            CIterator<T> operator= (const CIterator<T> &It) noexcept;
    };
}

#endif // __CITERATOR_H__
