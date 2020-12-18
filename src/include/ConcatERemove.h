#ifndef CONCAT_E_REMOVE_H
#define CONCAT_E_REMOVE_H
//-----------------------------------------------------------------
#include <iostream>
//-----------------------------------------------------------------
#define TAMANHO 100
#define ALPHABETSIZE 26
//-----------------------------------------------------------------
/*
*   Class Concat and Remove
*
**/
class ConcatERemove
{

    public:
        //----------------
        void getData(std::string &s, std::string &t, int &k);   
        void iniciaConcatERemove();
    //----------------
    private:
      
        bool concatERemove(std::string s, std::string t, int k);
        bool checkIfAlphabets(std::string alphabeta);
        void printAnswer(bool resp);
        void toLowerCase(std::string s);


};
#endif