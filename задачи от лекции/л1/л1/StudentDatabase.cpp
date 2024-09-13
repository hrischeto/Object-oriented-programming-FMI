#include <iostream>
#include <assert.h>

enum class Major {
    undefined,
    Inf,
    Cs,
    InfS,
    S
};

const char* getMajor(Major m)
{
    switch (m)
    {
    case Major::undefined:return "undefined";
    case Major::Inf: return "Inf";
    case Major::Cs: return "Cs";
    case Major::InfS: return "InfS";
    case Major::S: return "S";
    default:return " ";
    }
}

struct Student {
    char name[100] = "";
    unsigned fn = 0;
    Major major = Major::undefined;
};

void printStudent(const Student& st)
{
    std::cout <<"Name: "<< st.name <<"\nfn: " <<st.fn << "\nMajor: "<< getMajor(st.major) <<"\n"<< std::endl;
}

constexpr size_t  STUDENTS_MAX_SIZE = 10;
struct StudentDataBase
{
    size_t studentsCount;
    Student students[STUDENTS_MAX_SIZE];
};

void sortStudents(StudentDataBase& database, bool(*isLess)(const Student& lhs, const Student& rhs))
{
    assert(database.studentsCount <= STUDENTS_MAX_SIZE);

    for (int i = 0;i < database.studentsCount - 1;i++)
    {
        int minElementIndex = i;

        for (int j = i+1;j < database.studentsCount;j++)
        {
            if(isLess(database.students[j], database.students[minElementIndex]))
                minElementIndex=j;
        }

        if (minElementIndex != i)
            std::swap(database.students[i], database.students[minElementIndex]);
        
    }
}

void printDatabase(const StudentDataBase& database)
{
    assert(database.studentsCount <= STUDENTS_MAX_SIZE);

    for (int i = 0; i < database.studentsCount; i++)
        printStudent(database.students[i]);
}

enum class Criteria
{
    sortByName,
    sortByFn,
    sortByMajor
};

void sortByCriteria(StudentDataBase& database, Criteria cr)
{
    assert(database.studentsCount <= STUDENTS_MAX_SIZE);

    switch (cr)
    {
    case Criteria::sortByName:
        return sortStudents(database, [](const Student& lhs, const Student& rhs) {return std::strcmp(lhs.name, rhs.name) < 0;});
    case Criteria::sortByMajor:
        return sortStudents(database, [](const Student& lhs, const Student& rhs) {return (int)lhs.major < (int)rhs.major;});
    case Criteria::sortByFn:
        return sortStudents(database, [](const Student& lhs, const Student& rhs) {return lhs.fn < rhs.fn;});
    }

}
//
//int main() {
//    StudentDataBase s =
//    {
//        3,
//        {
//            {"Petur", 12, Major::InfS},
//            {"Ivan", 12345, Major::Cs},
//            {"Aleksandur", 56, Major::S}
//        }
//    };
//
//    printDatabase(s);
//
//    sortByCriteria(s, Criteria::sortByName);
//
//    printDatabase(s);
//
//    sortByCriteria(s, Criteria::sortByMajor);
//
//    printDatabase(s);
//
//    sortByCriteria(s, Criteria::sortByFn);
//
//    printDatabase(s);
//}