#include<iostream>
#include<string>
#include<ctime>
#include <cstdlib>

void randomChoice(std::string &keyword)
{
  srand(time(NULL));
  int random = rand()%6;
  switch(random)
    {
      case 0:
        keyword = "яблоко";
        break;
      case 1:
        keyword = "банан";
        break;
      case 2:
        keyword = "малина";
        break;
      case 3:
        keyword = "арбуз";
        break;
      case 4:
        keyword = "огурец";
        break;
      case 5:
        keyword = "дыня";
        break;
      case 6:
        keyword = "манго";
        break;
    }
}

int main()
{
  setlocale(LC_ALL,"rus");
  std::string keyword;
  randomChoice(keyword);
  std::cout<<"\t\t\t\t\tИгра 'угадайка'.\n"<<"\t\t\t\t\tУгадайте слово.\n\n"<<"1. яблоко\n2. банан\n3. малина\n4. арбуз\n5. огурец\n6. дыня\n7. манго\n\n";
  while(true)
  {
    std::string word;
    std::cout<<"Введите слово: ";
    std::cin>>word;
    if (word==keyword)
    {
      std::cout<<"Поздравляем! Вы победили! Загаданное слово: "<<keyword<<"\n";
      return 0;
    } else
    {
      std::cout<<"Неправильно!\n";
    }
  }
}
