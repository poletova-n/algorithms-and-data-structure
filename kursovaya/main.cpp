#include <iostream>
#include "hash.hpp"
#include "table.hpp"
#include <string>

int main() {
  setlocale(LC_ALL, "Russian");
  std::cout<<"------------------------------------------- \n";
  std::cout<<"Create table with default size: \n";
  Table<> tabl;
  std::cout<<"Create table with default size: completed! \n";
  std::cout<<"------------------------------------------- \n";

  std::cout<<"------------------------------------------- \n";
  std::cout<<"Fill table: \n";
  tabl.Add("cat", "кот");
  tabl.Add("cat", "кошак");
  tabl.Add("cat", "кошка");
  tabl.Add("dog", "собака");
  tabl.Add("cloud", "облако");
  tabl.Add("shake", "трясти");
  tabl.Add("snake", "змея");
  tabl.Add("snake", "змей");
  std::cout<<"Fill table: completed! \n";
  std::cout<<"------------------------------------------- \n";
  std::cout<<"Test Search function: \n";
  tabl.Search("cat");
  tabl.Search("shake");
  tabl.Search("snake");
  std::cout<<"Test Search function: completed! \n";
  std::cout<<"------------------------------------------- \n";

  std::cout<<"------------------------------------------- \n";
  std::cout<<"Check Errors: \n";
  try{
  Table<> err_1 (-1);
  }
  catch (std::invalid_argument &e){
    std::cout<< e.what();
  }
  try{
    Table<> err_2;
    err_2.Add("a","а");
  }
  catch (std::invalid_argument &e){
    std::cout<< e.what();
  }
  try{
    Table<> err_3;
    err_3.Search("a");
  }
  catch (std::invalid_argument &e){
    std::cout<< e.what();
  }
  std::cout<<"Check Errors: completed! \n";
  std::cout<<"------------------------------------------- \n";

  std::cout<<"------------------------------------------- \n";
  std::cout<<"Check Delete function: \n";
  tabl.Delete("cat");
  if(tabl.Search("cat")){std::cout << "cat - NOT DELETED \n";}else{std::cout<<"cat - DELETED \n";}
  std::cout<<"Check Delete function: completed! \n";
  std::cout<<"------------------------------------------- \n";

  std::cout<<"------------------------------------------- \n";
  std::cout<<"Check destructor: \n";
  tabl.~Table();
  std::cout<<"Check destructor: completed!\n";
  std::cout<<"------------------------------------------- \n";
  return 0;
}
