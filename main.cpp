#include <iostream>			// cout
#include <ctime>            //srand(), rand()

#include "CNode.h"			// CNode
#include "CDuree.h"			// CDuree
#include "IziAssert.h"      // IZI_ASSERT()
#include "CList.h"          // CList

using namespace std;
using namespace nsSdD;
using namespace nsUtil;

namespace
{
    int Rand (int min, int max)
    {
        return rand()% max + min;
    }

    void TestCDuree()
    {

        cout << "lol" << endl;
        CList<int> listeDuree(3, -4);
        listeDuree.push_front(2);
        CList<int> liste2 (listeDuree);
        listeDuree.push_front(2);
        //listeDuree2.push_back(4);
        //listeDuree = listeDuree2;

        liste2.afficher();
        liste2.clear();
        liste2.afficher();
        listeDuree.push_front(4);
        listeDuree.remove(2);
        CList<int> listeDuree2(listeDuree);   //copie de listeDuree
        //CList<int> listeDuree3 (5, -3);

        CList<int> listeSort;
        listeSort.push_back(0);
        listeSort.push_back(5);
        listeSort.push_back(-2);
        listeSort.push_back(7);
        listeSort.push_back(6);
        listeSort.push_back(8);
        listeSort.push_back(100);
        listeSort.push_back(-2);
        listeSort.push_back(0);
        listeSort.afficher();
        cout << "sort()" << endl;
        listeSort.sort();
        listeSort.afficher();
        cout << "reverse()" << endl;
        listeSort.reverse();
        listeSort.afficher();



       cout << "On créer 1 CListe de " << "\033[34mCDUREE " << "et une copie de ce " << "\033[34mCList" << endl;
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
/*
       IZI_ASSERT(listeDuree == listeDuree2);

       // Test push_front() et pop_front()
       cout << "On ajoute un" << "\033[34mCDUREE " << "au début de la première "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.push_front(new CDUREE::CDuree(Rand(1,300))));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT(!(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "au début de la première " <<"\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.pop_front());
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT(!(listeDuree == listeDuree2));
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
    //srand(time(NULL));
    TestCDuree();
    return 0;
}

