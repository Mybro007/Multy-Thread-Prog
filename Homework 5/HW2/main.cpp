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
        keyword = "������";
        break;
      case 1:
        keyword = "�����";
        break;
      case 2:
        keyword = "������";
        break;
      case 3:
        keyword = "�����";
        break;
      case 4:
        keyword = "������";
        break;
      case 5:
        keyword = "����";
        break;
      case 6:
        keyword = "�����";
        break;
    }
}

int main()
{
  setlocale(LC_ALL,"rus");
  std::string keyword;
  randomChoice(keyword);
  std::cout<<"\t\t\t\t\t���� '��������'.\n"<<"\t\t\t\t\t�������� �����.\n\n"<<"1. ������\n2. �����\n3. ������\n4. �����\n5. ������\n6. ����\n7. �����\n\n";
  while(true)
  {
    std::string word;
    std::cout<<"������� �����: ";
    std::cin>>word;
    if (word==keyword)
    {
      std::cout<<"�����������! �� ��������! ���������� �����: "<<keyword<<"\n";
      return 0;
    } else
    {
      std::cout<<"�����������!\n";
    }
  }
}
