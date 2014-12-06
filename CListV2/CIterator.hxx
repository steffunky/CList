#ifndef __CITERATOR_HXX__
#define __CITERATOR_HXX__

#include "CIterator.h"

#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDIT nsSdD::CIterator<T>

TEMPLINL
SDDIT::CIterator<T>(const Ptr_CNode &CurrentNode) noexcept
    : m_CurrentNode(CurrentNode)
{

}

TEMPLINL
typename SDDIT::CIterator<T> SDDIT::operator++ () noexcept
{
    m_CurrentNode = m_CurrentNode->GetSuivant();
}

TEMPLINL
typename SDDIT::CIterator<T> SDDIT::operator++ (int) noexcept
{
    CIterator<T> temp = *this;
    ++(*this);
    return temp;
}

TEMPLINL
typename SDDIT::Ptr_CNode& SDDIT::operator* () noexcept
{
    return std::shared_ptr<m_CurrentNode>;
}

TEMPLINL
typename Ptr_CNode SDDIT::operator-> () noexcept
{
    return m_CurrentNode;
}

TEMPLINL
bool SDDIT::operator ==(const CIterator<T> &It) noexcept
{
    return m_CurrentNode == It.GetCurrentNode();
}

TEMPLINL
typename SDDIT::Ptr_CNode GetCurrentNode () const noexcept
{
    return m_CurrentNode;
}

TEMPLINL
typename SDDIT::CIterator<T> SDDIT::operator= (const CIterator<T> &It) noexcept
{
    m_CurrentNode = It.GetCurrentNode();
}

TEMPLINL
typename SDDIIT::CIterator<T> SDDIT::operator-- () noexcept
{
    m_CurrentNode = m_CurrentNode->GetPrecedent();
}

TEMPLINL
typename SDDIT::CIterator<T> SDDIT::operator-- (int) noexcept
{
    CIterator<T> temp = *this;
    --(*this);
    return temp;
}

#undef TEMPL
#undef TEMPLINL
#undef SDDIT

#endif // CITERATOR_HXX
