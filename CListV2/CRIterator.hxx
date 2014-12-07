#ifndef __CRITERATOR_HXX__
#define __CRITERATOR_HXX__

#include "CRIterator.h"

#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDIT nsSdD::CRIterator<T>

TEMPLINL
SDDIT::CRIterator(const Ptr_CNode &CurrentNode) noexcept
    : m_CurrentNode(CurrentNode)
{

}

TEMPLINL
SDDIT::CRIterator(const CRIterator &It) noexcept
    : m_CurrentNode(It.GetCurrentNode())
{}

TEMPLINL
typename SDDIT SDDIT::operator++ () noexcept
{
    m_CurrentNode = m_CurrentNode->GetPrecedent();
    return *this;
}

TEMPLINL
typename SDDIT SDDIT::operator++ (int) noexcept
{
    CRIterator<T> temp = *this;
    ++(*this);
    return temp;
}

TEMPLINL
typename SDDIT::Ptr_CNode& SDDIT::operator* () noexcept
{
    return *m_CurrentNode;
}

TEMPLINL
typename SDDIT::Ptr_CNode SDDIT::operator-> () noexcept
{
    return m_CurrentNode;
}


TEMPLINL
bool SDDIT::operator ==(const CRIterator<T> &It) noexcept
{
    return m_CurrentNode == It.GetCurrentNode();
}

TEMPLINL
typename SDDIT::Ptr_CNode SDDIT::GetCurrentNode () const noexcept
{
    return m_CurrentNode;
}

TEMPLINL
typename SDDIT SDDIT::operator= (const CRIterator<T> &It) noexcept
{
    m_CurrentNode = It.GetCurrentNode();
    return *this;
}

TEMPLINL
typename SDDIT SDDIT::operator-- () noexcept
{
    m_CurrentNode = m_CurrentNode->GetSuivant();
    return *this;
}

TEMPLINL
typename SDDIT SDDIT::operator-- (int) noexcept
{
    CIterator<T> temp = *this;
    --(*this);
    return temp;
}

TEMPLINL
bool SDDIT::operator!= (const CIterator<T> &It) noexcept
{
    return !(*this == It);
}

#undef TEMPL
#undef TEMPLINL
#undef SDDIT

#endif // CITERATOR_HXX
