#ifndef __CRITERATOR_H__
#define __CRITERATOR_H__

#include "CIterator.h"

namespace nsSdD
{
    template <typename T>
    class CRIterator
    {
        typedef std::shared_ptr<nsSdD::CNode<T>> Ptr_CNode;
    private :
        Ptr_CNode m_CurrentNode;
    public :
        CRIterator (const Ptr_CNode &CurrentNode = nullptr) noexcept;
        CRIterator (const CRIterator &It) noexcept;
        CRIterator operator++ () noexcept;
        CRIterator operator++(int) noexcept;
        CRIterator operator-- () noexcept;
        CRIterator operator-- (int) noexcept;
        Ptr_CNode GetCurrentNode() const noexcept;
        Ptr_CNode operator->() noexcept;
        Ptr_CNode& operator* () noexcept;
        bool operator==(const CRIterator<T> &It) noexcept;
        CRIterator operator= (const CRIterator<T> &It) noexcept;
        bool operator!= (const CRIterator<T> &It) noexcept;
    };
}

#endif // CRITERATOR_H
