#include <iostream>
using namespace std;
//include <cstudio>

//global vars and methods
const int N = 10;
int **A = 0;

int **arrayInit(int N);
void showArrayContents();
int **populateArray(int N);
void searchValidEntries(int XL, int YL, int XH, int YH);
void garbageCollect();

/**
 * @brief implementations of the array, just filling with
 * @param height 
 * @param width 
 * @return int** 
 */
int **arrayInit(int N)
{
  int height = N;
  int width = N;
  A = new int *[height];

  for (int i = 0; i < height; i++)
  {
    A[i] = new int[width];
    for (int j = 0; j < width; j++)
    {
      A[i][j] = 0;
    }
  }

  return A;
}
/**
 * @brief displays the array contents
 * O(N^2) runtime
 */
void showArrayContents()
{
  printf("Array contents: \n");
  for (int h = 0; h < N; h++)
  {
    for (int w = 0; w < N; w++)
    {
      printf("%i |", A[h][w]);
    }
    printf("\n");
  }
}

void garbageCollect()
{
  printf("\n");
  printf("Cleaning up memory...\n");
  for (int h = 0; h < N; h++) // loop variable wasn't declared
  {
    delete[] A[h];
  }
  delete[] A;
  A = 0;
  printf("Ready.\n");
}

int **populateArray(int N)
{
  int populant = 20000;

  do
  {
    int i = rand() % N;
    int j = rand() % N;
    A[i][j] += 1;
    populant--;
  } while (populant > 0);

  return A;
}
void searchValidEntries(int XL, int YL, int XH, int YH)
{
  printf("\nBox contents: \n");
  int bH = XH - XL;
  int bW = YH - YL;
  cout << "bH: " << bW << " bW: " << bW << endl;
  for (int bi = XL; bi < XH; bi++)
  {
    for (int bj = YL; bj < YH; bj++)
    {
      if (A[bi][bj] == 0)
      {
        continue;
      }
      else
      {
        printf("%i |", A[bi][bj]);
      }
      //printf(" ");
    }
    printf("\n");
  }
}

int main()
{
  printf("Creating a 2D array2D\n");
  printf("\n");

  int **A = arrayInit(N);
  printf("Array sized [%i,%i] created.\n\n", N, N); //Done

  // print contents of the array2D
  //showArrayContents(); //Zeros will be displayed
  populateArray(N);
  showArrayContents();
  searchValidEntries(0, 0, 2, 2);
  garbageCollect();
}