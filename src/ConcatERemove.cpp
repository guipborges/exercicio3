/**
 * 3. Considere uma string contendo caracteres minúsculos do alfabeto português. Você pode executar dois tipos de operações nesta string:
*  a. Concatenar um caractere minúsculo do alfabeto português ao final da string.
*  b. Remover o último caractere da string. Se a string estiver vazia, ela permanecerá vazia.
*
*  Dado um número inteiro k e duas strings s e t, determine se você consegue converter s em t através de exatamente k operações descritas acima sobre s. Se possível, o programa imprime 'sim', do contrário imprime 'não'.
*
*  Por exemplo, string s = [a, b, c] e string t = [d, e, f]. O número de movimentos k = 6. Para converter s em t, primeiro removemos todos os caracteres usando 3 movimentos. Em seguida concatenamos cada um dos caracteres de t na ordem. No sexto movimento, você terá a string s esperada. Se houver mais movimentos disponíveis que o necessário, eles podem ser eliminados executando múltiplas remoções em uma string vazia. Se houver movimentos a menos, não seria possível criar a nova string.
*
*   Desenvolva um programa que implementa e utiliza a função ConcatERemove(s,t,k). Ela deve retornar os resultados 'sim' ou 'não'.
*   A função tem os seguintes parâmetros:
*   s: string inicial
*   t: string desejada
*   k: um número inteiro que representa o número de operações

*   Formato de entrada
*   A primeira linha contêm a string s, a string inicial.
*   A segunda linha contém a string t, a string desejada.
*   A terceira linha contém um inteiro k, o número de operações.
*
*   Limitações
*   a) 1 <= |s| <= 100
*   b) 1 <= |t| <= 100
*   c) 1 <= k <= 100
*   d) s e t consiste de letras minúsculas do alfabeto português, ascii[a-z]
*
*   Formato de saída
*   Imprima 'sim' se você puder obter a string t executando exatamente k operações sobre a string s, e imprime 'não' no caso contrário.
**/
//-------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <random>
#include <locale>         // std::locale, std::tolower
//-------------------------------------------------------------------
#include "include/ConcatERemove.h"
//-------------------------------------------------------------------
/*
*   Receives data provided by user
*
*/
void ConcatERemove::getData(std::string &s, std::string &t, int &k)
{
    //----
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Welcome                                                           \n";
    std::cout << "Initial/Desired string rules: must be only letters <100 characters\n";
    std::cout << "Must contain one lowercase letter                                 \n";
    std::cout << "Operations: must be < 100                                         \n";
    std::cout << "------------------------------------------------------------------\n";
    //----
    do
    {
        std::cout << "Type the initial string:";
        std::getline(std::cin, s); 
    } while (s.length() > 100 || checkIfAlphabets(t) == false);
    //----
    do
    {
        std::cout << "Type the desired string:" ;
        std::getline(std::cin, t);
    } while ((t.length() > 100) || checkIfAlphabets(t) == false);
    //----
    //ensures that the string will be in lowercase
    toLowerCase(s);
    toLowerCase(t);
    //----
    do
    {
        std::cout << "Type the number of operations:" ;
        std::cin >> k;
    } while (k > 100);
}
//-------------------------------------------------------------------
/*
*   Concat and Remove
*
*/
bool ConcatERemove::concatERemove(std::string s, std::string t, int k)
{
    //initial variables
    int position = 0;
    int op_remove = 0;
    int op_concatenate = 0;
    int size_str_t = t.length();
    int size_str_s = s.length(); 
    int minor = std::min(size_str_t,size_str_s);

    //protection
    if (size_str_s < size_str_t )
    {
        return false;
    }
    //protection in case the difference between the string size is greater 
    //than the maximum number of operations allowed
    if(std::abs((size_str_s - size_str_t)) > k)
    {
        return false;
    }
    //keeps the position where the two strings are equal.
    int i = 0;
    while(s[i] == t[i] && position < minor)
    {
        position++;
        i++;
    }
    //Checks the number of character removal operations required
    for (int i = size_str_s; i > position; i--)
    {
        op_remove++;
    }
    //checks necessary addition operations 
    op_concatenate = size_str_t - position;
    //It checks if the necessary operations 
    //are smaller than the maximum operations.
    if(op_concatenate + op_remove > k)
    {
        return false;
    }
    return true;
}
//-------------------------------------------------------------------
/*
*   Main initialization method
*
*/
void ConcatERemove::iniciaConcatERemove()
{
    //local variables
    std::string s, t;
    int k = 0;
    //requests data from the user
    getData(s, t, k); 
    //checks if it is possible to achieve the goal
    bool resp = concatERemove(s, t, k);
    //print
    printAnswer(resp);

}
//-------------------------------------------------------------------
/*
*   Prints answer
*
*/
void ConcatERemove::printAnswer(bool resp)
{
    if (resp == false)
    {
       std::cout<< "nao" << std::endl;
    }

    if (resp == true)
    {
        std::cout<< "sim" << std::endl;
    }
}
//----------------------------------------------------------------------
/* 
*  Checking for alphabet
*
*/
bool ConcatERemove::checkIfAlphabets(std::string alphabeta)
{
    int i = 0;
    while (alphabeta[i])
    {
        if (!isalpha(alphabeta[i]))
        {
            std::cout << "\n\n";
            std::cout << "!!!! Wrong string format !!!!! " << std::endl;
            std::cout << "\n\n";
            return false;
        }
        i++;
    }
    return true;
}
//----------------------------------------------------------------------
/* 
*  Convert String to LowerCase
*
*/
void ConcatERemove::toLowerCase(std::string s)
{
  std::locale loc;
  std::setlocale(LC_ALL, "pt_BR.UTF-8");

    for (std::string::size_type i = 0; i < s.length(); ++i)
    {
        std::tolower(s[i],loc);
    }
}