#include <iostream>
#include <string>
using namespace std;
typedef struct
{
  string name;
  int score;
} student;

int main()
{
  int count = 0;
  int fun = 0;
  student stus[1000], tmp;

  while (scanf("%d%d", &count, &fun) != EOF)
  {
    for (int i = 0; i < count; i++)
    {
      cin >> stus[i].name >> stus[i].score;
    }
    if (fun == 1)
    {
      for (int i = 1; i < count; i++)
      {
        for (int j = 0; j < count - i; j++)
        {
          if (stus[j].score > stus[j + 1].score)
          {
            tmp = stus[j];
            stus[j] = stus[j + 1];
            stus[j + 1] = tmp;
          }
        }
      }
    }
    else if (fun == 0)
    {
      for (int i = 1; i < count; i++)
      {
        for (int j = 0; j < count - i; j++)
        {
          if (stus[j].score < stus[j + 1].score)
          {
            tmp = stus[j];
            stus[j] = stus[j + 1];
            stus[j + 1] = tmp;
          }
        }
      }
    }

    for (int i = 0; i < count; i++)
    {
      cout <<stus[i].name << " " << stus[i].score << endl;
    }
  }
  return 0;
}
