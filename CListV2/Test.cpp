#include <iostream>			// cout
#include "CNode.h"			// CNode
#include "CDuree.h"			// CDuree
#include <ctime>            //srand(), rand()
#include "IziAssert.h"      // IZI_ASSERT()

template <typename T>
#define CNODET nsSdD::CNode<T>
#define CDUREE nsUtil::CDuree
typedef  nsSdD::CList CLIST;
typedef CNODET::CNode<CDUREE::CDuree> CNODEDUREE;

namespace
{
    int Rand (int min, int max)
    {
        return rand()% max + min;
    }

    void TestCDuree()
    {
        CLIST::CList listeDuree = CLIST::CList(10);
        for (unsigned i = 0; i< 10; ++i,)
        {
            listeDuree.push_back(new CNODE::CNode(new CDUREE::CDuree(Rand(1,300))));
        }

        CLIST::CList listeDuree2(listeDuree);   //copie de listeDuree


       cout << "On créer 1 CListe de" << "\033[34mCDUREE " << "et une copie de ce" << "\033[34mCList" << endl << endl << endl;
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT(listeDuree == listeDuree2);
       // Test push_front() et pop_front()
       cout << "On ajoute un" << "\033[34mCDUREE " << "au début de la première "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.push_front(new CDUREE::CDuree(Rand(1,300))));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT( !(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "au début de la première " <<"\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.pop_front())
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT( !(listeDuree == listeDuree2));
       // Test push_back() et pop_back()
       cout << "On ajoute un" << "\033[34mCDUREE " << "à la fin de la première "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.push_back(new CDUREE::CDuree(Rand(1,300))));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT( !(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "a la fin de la première " <<"\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.pop_back());
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT(listeDuree == listeDuree2);
       //Test insert et erase
       //
       //   A DECOMMENTER POUR LA V2
       //
       //
       /*
       cout << "On ajoute un" << "\033[34mCDUREE " << "à la 5e position de "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.insert(5,new CDuree()));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT( !(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "à la 5e position de "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.erase(5));
       */
       
       
    }

}
int main()
{
    srand(time(NULL));
    return 0;
}

