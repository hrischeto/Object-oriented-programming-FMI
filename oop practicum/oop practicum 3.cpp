

#include <iostream>
#include <fstream>

///*zad1*/
//
//const char SEP_FOR_ROWS = '|';
//const char SEP_FOR_COLS = ',';
//constexpr size_t BUFF_MAX_SIZE = 1024;
//
//
//void freeMatrix(int** mtx, size_t rows)
//{
//    if (!mtx)
//        return;
//
//    for (int i = 0; i < rows;i++)
//        delete[]mtx[i];
//
//    delete[]mtx;
//}
//
//size_t countRowsAndCols(std::ifstream& file, char sep)
//{
//    int count = 0;
//    while (!file.eof())
//    {
//        if (file.get() == sep)
//            count++;
//    }
//
//    return count + 1;
//}
//
//
//int atoi(const char* str)
//{
//    if (!str)
//        return -1;
//
//    int num = 0;
//    
//    while (*str)
//    {
//        (num *= 10) += (*str - '0');
//        str++;
//    }
//
//    return num;
//}
//
//int atoiNegative(const char* str)
//{
//    int num = 0;
//    if (!str)
//        return -1;
//
//    if (*str == '-')
//    {
//        str++;
//        num = -1* atoi(str);
//    }
//    else
//    {
//        num = atoi(str);
//    }
//
//    return num;
//}
//int getNumberFromFile(std::ifstream& file)
//{
//    char buff[BUFF_MAX_SIZE];
//    file.getline(buff, BUFF_MAX_SIZE, SEP_FOR_COLS);
//    
//    int num = atoiNegative(buff);
//
//    return num;
//}
//
//void readMatrix(std::ifstream& file, int** matrix, size_t& rows)
//{
//    rows = countRowsAndCols(file, SEP_FOR_ROWS);
//    int cols = countRowsAndCols(file, SEP_FOR_COLS);
//
//    for (int i = 0;i < rows;i++)
//    {
//        for (int j = 0;j < cols;j++)
//        {
//            matrix[i][j] = getNumberFromFile(file);
//        }
//    }
//}
//void exerciseOne()
//{
//    std::ifstream file1("matxix 1.txt");
//    std::ifstream file2("matxix 2.txt");
//
//    if (!file1.is_open())
//    {
//        std::cout << "Error while reading" << std::endl;
//        return;
//    }
//    if (!file2.is_open())
//    {
//        std::cout << "Error while reading" << std::endl;
//        return;
//    }
//
//    size_t rows1;
//    int** matrix1 =  new int* [rows1];
//
//    size_t rows2;
//    int** matrix2 = new int* [rows2];
//
//
//
//    freeMatrix(matrix1, rows1);
//    freeMatrix(matrix2, rows2);
//}

int main()
{
    std::ofstream file("file.txt", 16);
    if (!file.is_open())
    {
        std::cout << "error";
        return -1;
    }

}
