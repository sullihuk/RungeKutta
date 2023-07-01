#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  
  void Shell(int a[], int n);
  void printer (int ar[], int en);
  file = fopen("sort1.txt", "r");
  // Проверка ошибки открытия файла
  if (file==NULL) {
    printf("Файл не найден....");
    return 0;
  }
  int n=0,y;
  int *a;
  // пока не конец файла f
  while (!feof(file))
  {
    // читать элемент и
    int z = fscanf(file,"%d",&y);
    // если произошла ошибка при считывании, то закончить
    // выполнение цикла
    if(z!=1) break;
    // увеличивать счетчик.
    n++;
  }
  // После окончания цикла в переменной n хранится
  // количество целых чисел, записанных в файле.
  // Выделить память под массив.
  a = ( int*)malloc(sizeof(int) *n);
  // Указатель чтения-записи файла передвинуть в начало.
  fseek(file,0,SEEK_SET);
  // Читать n целых чисел из файла в массив.
  for( int i=0;i<n;i++)
  fscanf(file,"%d",&a[i]);

  printf("Прочитан массив: \n");

  //for(int i=0;i<n;i++) 
  //printf("%5d\n",a[i]);

    /*FILE *file;
    char line[10];
    int number;
    String arr[500001];
    void printer (int ar[500001]);
    void quick_sort(int* a, int first, int last);
    void Shell(int *a, int n);

    // Open the file for reading
    file = fopen("sort1.txt", "r");
    if (file == NULL) {
        printf("File open error.\n");
        return 1;
    }

    while(!feof(file))
    {
      int i = 0;
      // Read a line from the file
      //fgets(line, sizeof(line), file);
      fscanf(file, "%d", &arr[i]);
          // Convert each token to an integer
          //number = atoi(line);
         // arr[i] = number;
          //arr[i] = line;
      i++;
    }*/

    // Close the file
    fclose(file);
    printer(a, n);
    Shell(a, n); 
    printer(a, n);
  return 0;
}

void printer (int ar[], int en)
{
  for(int i = 0; i<en; i++)
  {
          printf("nO - %d.The read number is: %d\n",i, ar[i]);
  }
}

void Shell(int a[], int n)
{
  int i,j,k, x;
  for (k=n/2; k>0; k=k/2)
  for (i=k; i<n; i++)
  {
    x=a[i];
    for (j=i; j>=k; j-=k)
    {
      if (x<a[j-k]) a[j]=a[j-k];
      else break;
    }
    a[j]=x;
  }
}


