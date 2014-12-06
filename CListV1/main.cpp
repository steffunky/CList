#include <iostream>                     // cout
#include <ctime>            //srand(), rand()

#include "CNode.h"                      // CNode
#include "CDuree.h"                     // CDuree
#include "IziAssert.h"      // IZI_ASSERT()
#include "CList.h"          // CList

using namespace std;
using namespace nsSdD;
using namespace nsUtil;

namespace
{
    template<typename T>
    bool areListsEquals(CList<T> list1, CList<T> list2)
    {
        if (list1.size() != list2.size())
            return false;
        CNode<T> elem1;
        CNode<T> elem2;
        for (elem1 = list1.front(), elem2 = list2.front();
               !(elem1.GetData() == list1.back()->GetData());
              elem1 = elem1.GetSuivant(), elem2=elem2.GetSuivant())
             if (elem1.GetData() != elem2.GetData())
                return false;
        return true;
    }

    int Rand (int min, int max)
    {
        return rand()% max + min;
    }

    template <typename T>
    void afficherList(const CList<T> & List) noexcept
    {
        cout << "\n\nAffichage de la liste " << endl;
        for (std::shared_ptr<CNode<T>> Ptr(List.front()); Ptr != List.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
        {
            cout << Ptr->GetData() << "; ";
        }
        cout << "\nfin de la liste \n\n" << endl;
    }

    void TestCDuree()
    {
        CList<int> Test1(3, -4);
        CList<int> Test2(3, -4);


        if (areListsEquals(Test1,Test2))
            cout << "xd" << endl;
        else
            cout << "why" << endl;

       cout << "\33[37mOn créer 1 \033[34mCList\33[37m de " << "\033[34mCDUREE\33[37m : \033[35mlisteCDuree1\33[37m "
            << "et une copie de ce " << "\033[34mCList\33[37m de \033[34mCDUREE\33[37m : \033[35mlisteCDuree2\33[37m" << endl;
       cout << "\33[37mOn vérifie que les 2 " << "\033[34mCList\33[37m " << "soit bien égaux" << endl;
       IZI_ASSERT(areListsEquals(Test1,Test2));
       // Test push_front() et pop_front()
       cout << "\33[37mOn ajoute un" << " \033[34mCDUREE \33[37m" << "au début de la première "<< "\033[34mCList\33[37m" << endl;
       Test1.push_front(5);
       cout << "\33[37mOn vérifie que les 2" << " \033[34mCList\33[37m " << "soit bien différents" << endl;
       IZI_ASSERT(!(areListsEquals(Test1,Test2)));
       cout << "\33[37mOn supprime le " << "\033[34mCDUREE\33[37m " << "au début de la première " <<"\033[34mCList\33[37m" << endl;
       Test1.pop_front();
       cout << "\33[37mOn vérifie que les 2" << " \033[34mCList\33[37m " << "soit bien égaux" << endl;
       IZI_ASSERT(areListsEquals(Test1,Test2));
       // Test push_back() et pop_back()
       cout << "\33[37mOn ajoute un " << "\033[34mCDUREE\33[37m " << "à la fin de la première "<< "\033[34mCList\33[37m" << endl;
       Test1.push_back(5);
       cout << "\33[37mOn vérifie que les 2 " << "\033[34mCList\33[37m " << "soit bien différents" << endl;
       IZI_ASSERT( !(areListsEquals(Test1,Test2)));
       cout << "\33[37mOn supprime le " << "\033[34mCDUREE\33[37m " << "a la fin de la première " <<"\033[34mCList\33[37m" << endl;
       Test1.pop_back();
       cout << "\33[37mOn vérifie que les 2 " << "\033[34mCList\33[37m " << "soit bien égaux" << endl;
       IZI_ASSERT(areListsEquals(Test1,Test2));

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << "\033[34mCDUREE\33[37m : \033[35mlisteCDuree3\33[37m "
            << "et une copie de ce " << "\033[34mCList\33[37m de \033[34mCDUREE\33[37m : \033[35mlisteCDuree4\33[37m" << endl;
       CList<int> Test3(5, 8);
       CList<int> Test4(5, 8);
       Test3.push_back(5);
       Test4.push_back(5);

       cout << "\33[37mOn echange les " << "\033[34mCNODE\33[37m "
            << "de \033[35mlisteCDuree2\33[37m et \033[35mlisteCDuree3\33[37m" << endl;
       Test2.swap(Test3);
       cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mlisteCDuree2\33[37m et \033[35mlisteCDuree4\33[37m "
            << "ainsi que \033[35mlisteCDuree1\33[37m et \033[35mlisteCDuree3\33[37m " <<"soit bien égaux" << endl;
       IZI_ASSERT(areListsEquals(Test2,Test4) && areListsEquals(Test1,Test3));

       cout << "\33[37mOn supprime le contenu " << "de \033[35mlisteCDuree3\33[37m " << "et on vérifie qu'il soit vide" << endl;
      Test3.clear();
      IZI_ASSERT(Test3.empty());

      cout << "\33[37mOn supprime un \033[34mCNODE\33[37m dont on sait que sa donnée est présente dans la " <<
              "\033[34mCList\33[37m :\033[35mlisteCDuree4\33[37m" << endl;
      Test4.remove(Test4.back()->GetData());
      cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mlisteCDuree2\33[37m et \033[35mlisteCDuree4\33[37m "
           << "soit bien différents" << endl;
      IZI_ASSERT(!(areListsEquals(Test1,Test2)));

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << "\033[34mCDUREE\33[37m : \033[35mlisteCDuree5\33[37m "<<
                "dont toutes les données des \033[34mCNODE\33[37m sont les mêmes et on affiche sa taille \n" << endl;

       CList<int> Test5(4,9);

       cout <<"\t Taille de \033[35mlisteCDuree5\33[37m : \033[36m" << Test5.size() << '\n' << endl;
       cout << "\33[37mOn applique la fonction qui supprime tout les doublons, la taille doit donc être de \033[36m 0 \033[37m \t"
            << endl;
       Test5.unique();
       cout <<"\t Taille de \033[35mlisteCDuree5\33[37m : \033[36m" << Test5.size() << '\n' << endl;

       cout << "\33[37m On ajoute des valeurs aléatoires à \033[35mlisteCDuree5\33[37m et on affiche cette \033[34mCList\33[37m" << endl;
       for (int i = 0; i < 15; ++i)
       {
            Test5.push_back(Rand(0,40));
       }
       afficherList(Test5);        //listeDuree.push_front(4);

       //listeDuree.remove(2);
       //CList<int> listeDuree2(listeDuree);   //copie de listeDuree
       //CList<int> listeDuree3 (5, -3);

       cout << "\33[37mOn range cette \033[34mCList\33[37m avec sort() et on affiche \033[35mlisteCDuree5\33[37m " << endl;
       Test5.sort();
       afficherList(Test5);

       cout << "\33[37mOn inverse l'ordre des valeurs de \033[35mlisteCDuree5\33[37m grâce à reverse et on l'affiche" << endl;
        Test5.reverse();
       afficherList(Test5);

       cout << "\33[37mOn affiche \033[35mlisteCDuree1\33[37m et \033[35mlisteCDuree5\33[37m \n," <<
               "on les fusionnes et on affiche le résultat qu'on insert dans \033[35mlisteCDuree5\33[37m" << endl;

       cout << "\n\n\033[35mlisteCDuree1\33[37m :"<< endl;
       afficherList(Test1);
       cout <<"\n\n\033[35mlisteCDuree5\33[37m :" << endl;
       afficherList(Test5);

       Test5.merge(Test1);
       cout << "\n\n \033[35mlisteCDuree1\33[37m + \033[35mlisteCDuree5\33[37m" << endl;
       afficherList(Test5);
       //faire assign && maxsize

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << "\033[34mCDUREE\33[37m : \033[35mlisteCDuree6\33[37m  vide"<<
                "et une seconde  \033[34mCList\33[37m de " << "\033[34mCDUREE\33[37m : \033[35mlisteCDuree7\33[37m "
                << "contenant 3 \033[34mCDUREE\33[37m identiques" << endl;
        CList<int> Test6;
        CList<int> Test7(3,10);
        cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mlisteCDuree6\33[37m et \033[35mlisteCDuree7\33[37m "
             << "soit bien différents" << endl;
        IZI_ASSERT(!(areListsEquals(Test6,Test7)));

        cout << "\33[37mOn assigne 3 valeurs à \033[35mlisteCDuree6\33[37m (les mêmes que celles de \033[35mlisteCDuree7\33[37m )"
             << "grâce à assign(3,Val) et on compare les 2 \033[34mCList\33[37m" << endl;
       Test6.assign(3,10);
       afficherList(Test6);
       afficherList(Test7);
       IZI_ASSERT(areListsEquals(Test6,Test7));

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << "\033[34mCDUREE\33[37m : \033[35mlisteCDuree8\33[37m  contenant"
            << "5  \033[34mCDUREE\33[37m, les mêmes que  \033[35mlisteCDuree6\33[37m et  \033[35mlisteCDuree7\33[37m" << endl;
       CList<int> Test8(5,10);
       cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mlisteCDuree6\33[37m et \033[35mlisteCDuree8\33[37m "
            << "soit bien différents" << endl;

       IZI_ASSERT(!(areListsEquals(Test6,Test8)));

       cout << "On change la taille de \033[35mlisteCDuree6\33[37m de 3 à 5 \033[34mCDUREE\33[37m, en comblant les 2 cases ajoutées"
            << "avec le même \033[34mCDUREE\33[37m que dans le reste de la \033[34mCList\33[37m grâce à resize(5,Val)" <<
               "et on vérifie que \033[35mlisteCDuree6\33[37m et \033[35mlisteCDuree8\33[37m soit bien égaux" << endl;
       Test6.resize(5,10);
       afficherList(Test6);
       afficherList(Test8);
       IZI_ASSERT(areListsEquals(Test6,Test8));

       cout <<"On tronque maintenant \033[35mlisteCDuree6\33[37m à 3 éléments, il devrait donc être égal à \033[35mlisteCDuree7\33[37m"
            <<", on utilise donc resize(3), et on vérifie l'égalité" << endl;
       Test6.resize(3, 0);
       afficherList(Test6);
       afficherList(Test7);
        IZI_ASSERT(areListsEquals(Test6,Test7));
       cout << "La taille maximum de notre \033[34mCList\33[37m est : " << Test8.max_size() << endl;

       /*
       void swap (CList<T> & List) noexcept;
       void clear () noexcept;

       void remove (const T & val) noexcept;
       void unique () noexcept;

       void sort () noexcept;
       void reverse () noexcept;

       void resize (unsigned n, const T& val = T()) noexcept;

       void merge (CList & x) noexcept;
       void assign (unsigned n, const T& val) noexcept;

       unsigned max_size() noexcept;

       void Remove (const Ptr_CNode & Node) noexcept;

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
    CList<int> list;
    list.resize(3, 2);
    list.pop_back();
    cout << "1" << endl;
    afficherList(list);
    list.assign(3, 5);
    list.push_back(4);
    afficherList(list);
    list.resize(2);
    afficherList(list);
    return 0;
}
