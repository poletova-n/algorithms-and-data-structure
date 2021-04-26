#include <iostream>
#include"sort.hpp"

int main()
{
  std::cout<<"Sort by counting with big numbers \n";
  double* arr = new double[5];
  arr[0] = 7777.55;
  arr[1] = 555.55;
  arr[2] = 22.55;
  arr[3] = 355.55;
  arr[4] = 411.55;
  std::cout<<"Unsorted array: \n";
  print_2(arr, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_2(arr, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}
  arr = sort_count<double>(arr, 5);
  std::cout<<"Array sorted by sort_count(): \n";
  print_2(arr, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_2(arr, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}

  std::cout<<"Sort by counting with small numbers \n";
  double* arr_c = new double[5];
  arr_c[0] = 7.55;
  arr_c[1] = 5.55;
  arr_c[2] = 2.55;
  arr_c[3] = 3.55;
  arr_c[4] = 4.55;
  std::cout<<"Unsorted array: \n";
  print_2(arr_c, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_2(arr_c, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}
  arr_c = sort_count<double>(arr_c, 5);
  std::cout<<"Array sorted by sort_count(): \n";
  print_2(arr_c, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_2(arr_c, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}


  std::cout << "Radix sort with a numbers with a big number of digits: \n";
  int arr_2_r[5] = {793579438, 500000 ,2456 ,30000 ,43221423};
  std::cout<<"Unsorted array: \n";
  print(arr_2_r, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_2_r, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}
  sort_digit(arr_2_r, 5);
  std::cout<<"Array sorted by sort_digit(): \n";
  print(arr_2_r, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_2_r, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}

  std::cout << "Radix sort with a numbers with a small number of digits: \n";
  int arr_2[5] = {7, 5 ,2 ,3 ,4};
  std::cout<<"Unsorted array: \n";
  print(arr_2, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_2, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}
  sort_digit(arr_2, 5);
  std::cout<<"Array sorted by sort_digit(): \n";
  print(arr_2, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_2, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}

  std::cout << "Bucket sort with a numbers with a small difference between them: \n";
  int arr_3[5] = {1, 2 ,2 ,1 ,2};
  std::cout<<"Unsorted array: \n";
  print(arr_3, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_3, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}
  bucket_sort(arr_3, 5);
  std::cout<<"Array sorted by bucket_sort(): \n";
  print(arr_3, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_3, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}

  std::cout << "Bucket sort with a numbers with a big difference between them: \n";
  int arr_3_b[5] = {10000, 500 ,9000 ,70 ,2000};
  std::cout<<"Unsorted array: \n";
  print(arr_3_b, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_3_b, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}
  bucket_sort(arr_3_b, 5);
  std::cout<<"Array sorted by bucket_sort(): \n";
  print(arr_3_b, 5);
  std::cout<<"\nArrray is ordered: ";
  if(check_sort_1(arr_3_b, 5)){std::cout<<"YES\n";}else{std::cout<<"NO\n";}

}

